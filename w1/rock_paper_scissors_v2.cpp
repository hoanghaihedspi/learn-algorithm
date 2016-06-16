// Wrong

#include "iostream"
#include "string"
#include "iomanip"

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

#define MAX 100

using namespace std;

inline void use_io_optimizations();
void output(int win[], int total[], int n);
int winer(string move1, string move2);
int convert(string move);

int main()
{
	use_io_optimizations();
	int n, k;
	int win[MAX + 1], total[MAX + 1];
	int user1, user2;
	int w;
	string move1, move2;
	while(1){
		cin >> n;
		if(n == 0) break;
		cin >> k;
		for(int i = 1; i <= n; i++){
			win[i] = 0;
			total[i] = k;
		}

		k = k * n * (n - 1) / 2;
		for(int i = 0; i < k; i++){
			cin >> user1 >> move1 >> user2 >> move2;
			w = winer(move1, move2);
			if(w == 1) win[user1]++;
			else if(w == 2) win[user2]++;
			else if(w == 0){ total[user1]--; total[user2]--; }
		}
		output(win, total, n);
	}
}

void output(int win[], int total[], int n)
{
	for(int i = 1; i <= n; i++){
		if(total[i] == 0) cout << "-" << endl;
		else cout << fixed << setprecision(3) << (float)win[i] / total[i] << endl;
	}
	cout << endl;
}

int winer(string move1, string move2)
{
	int m1 = convert(move1);
	int m2 = convert(move2);
	int res = (m1 - m2) % 3;
	return res > 0 ? res : res < 0 ? 3 + res : 0;
}

int convert(string move)
{
	if(move[0] == 'r') return ROCK;
	else if(move[0] == 'p') return PAPER;
	else if(move[0] == 's') return SCISSORS;
}

inline void use_io_optimizations()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}