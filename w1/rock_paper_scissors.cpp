/********************************************************
* https://open.kattis.com/problems/rockpaperscissors	*
* Copyright: haihv										*
********************************************************/


#include "iostream"
#include "string"
#include "vector"
#include "iomanip"
#include "algorithm"

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

#define MAX 100

using namespace std;

void output(vector<int> win, vector<int> lost);
int winer(string move1, string move2);
int convert(string move);
inline void use_io_optimizations() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	use_io_optimizations();
	int n, k;
	vector<int> win;
	vector<int> lost;
	int user1, user2;
	int w;
	string move1, move2;
	while(1){
		cin >> n;
		if(n == 0) break;

		win.resize(0);
		win.resize(n + 1);
		lost.resize(0);
		lost.resize(n + 1);

		cin >> k;
		k = k * n * (n - 1) / 2;
		for(int i = 0; i < k; i++){
			cin >> user1 >> move1 >> user2 >> move2;
			w = winer(move1, move2);
			if(w == 1){ win[user1]++; lost[user2]++; }
			else if(w == 2){ lost[user1]++; win[user2]++; }
		}
		output(win, lost);
	}
}

void output(vector<int> win, vector<int> lost)
{
	for(int i = 1; i < win.size(); i++){
		if(win[i] == 0 && lost[i] == 0) cout << "-" << endl;
		else cout << fixed << setprecision(3) << (float)win[i] / (win[i] + lost[i]) << endl;
	}
	cout << endl;
}

int winer(string move1, string move2)
{
	int m1 = convert(move1);
	int m2 = convert(move2);
	int res = ((m1 - m2) % 3);
	return res > 0 ? res : res < 0 ? 3 + res : 0;
}

int convert(string move)
{
	if(move[0] == 'r') return ROCK;
	else if(move[0] == 'p') return PAPER;
	else if(move[0] == 's') return SCISSORS;
}