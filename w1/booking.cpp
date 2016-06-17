/********************************************
* https://open.kattis.com/problems/booking	*
* Copyright: haihv							*
********************************************/

// Thuat toan: Xet theo truc thoi gian (timeline), so phong nhieu nhat tai 1 thoi diem la gia tri can tim.
// Do phuc tap: O(T)

#include "iostream"
#include "string"
#include "vector"
#include "ctime"

using namespace std;

typedef struct _Time
{
	time_t arrival;
	time_t departure;
} Time;

inline void use_io_optimizations();
Time input_time(int C, vector<time_t> &line);
int output(vector<Time> time, vector<time_t> line);
void insert(vector<time_t> &line, time_t x);

int main()
{
	use_io_optimizations();

	int T, B, C;
	vector<Time> time;
	vector<time_t> line;
	cin >> T;
	while(T--){
		time.resize(0);
		line.resize(0);
		cin >> B >> C;
		while(B--) time.push_back(input_time(C, line));
		cout << output(time, line) << endl;
	}
	return 0;
}

int output(vector<Time> time, vector<time_t> line)
{
	// if(line.size() == 0) return 0;
	int max = 0, tmp;
	time_t ct;
	for(int i = 0; i < line.size() - 1; i++){
		ct = line[i] + 1;
		tmp = 0;
		for(int j = 0; j < time.size(); j++){
			if(ct > time[j].arrival && ct < time[j].departure) tmp++;
			else if(ct > time[j].departure) time.erase(time.begin() + j--);
		}
		if(tmp > max) max = tmp;
	}
	return max;
}

Time input_time(int C, vector<time_t> &line)
{
	string s, ts;
	struct tm tmp[2];
	// random
	cin >> s;
	for(int i = 0; i < 2; i++){
		// date
		cin >> s;
		ts = s.substr(0, 4);
		tmp[i].tm_year = stoi(ts) - 1900;
		ts = s.substr(5, 2);
		tmp[i].tm_mon = stoi(ts) - 1;
		ts = s.substr(8, 2);
		tmp[i].tm_mday = stoi(ts);
		// time
		cin >> s;
		ts = s.substr(0, 2);
		tmp[i].tm_hour = stoi(ts);
		ts = s.substr(3, 2);
		tmp[i].tm_min = stoi(ts);
		tmp[i].tm_sec = 0;
	}
	time_t arrival = mktime(&tmp[0]);
	time_t departure = mktime(&tmp[1]) + C * 60;
	insert(line, arrival);
	insert(line, departure);
	return { arrival, departure };
}

void insert(vector<time_t> &line, time_t x)
{
	if(line.size() == 0){ line.push_back(x); return; }
	int l = 0, r = line.size() - 1;
	int t = (l + r) / 2;
	while(l <= r){
		if(line[t] == x) return;
		else if(line[t] < x) l = t + 1;
		else r = t - 1;
		t = (l + r) / 2;
	}
	if(line[t] < x) line.insert(line.begin() + t + 1, x);
	else line.insert(line.begin() + t, x);
}

inline void use_io_optimizations()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}