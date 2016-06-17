/********************************************
* https://open.kattis.com/problems/chess	*
* Copyright: haihv							*
********************************************/

/* Thuat toan: 	X, Y khac mau -> "Impossible"
*				X co the den truc tiep Y -> output. So buoc = 1
*				Xet tung o X co the den (<= 13), neu tu o do den duoc Y -> output. So buoc <= 2.
* Do phuc tap:	O(1) 
*/

#include "iostream"
#include "stdlib.h"

using namespace std;

typedef struct _Corrdinates
{
	char x;
	int y;
} Corrdinates;

inline void use_io_optimizations();;
bool impossible(Corrdinates X, Corrdinates Y);
Corrdinates path(Corrdinates X, Corrdinates Y);

int main()
{
	use_io_optimizations();

	int n;
	cin >> n;
	Corrdinates X, Y;
	for(int i = 0; i < n; i++){
		cin >> X.x >> X.y >> Y.x >> Y.y;
		if(impossible(X, Y)) cout << "Impossible" << endl;
		else if(X.x == Y.x && X.y == Y.y) cout << "0 " << X.x << " " << X.y << endl;
		else if(abs(X.x - Y.x) == abs(X.y - Y.y)) cout << "1 " << X.x << " " << X.y << " " << Y.x << " " << Y.y << endl;
		else{
			Corrdinates p = path(X, Y);
			cout << "2 " << X.x << " " << X.y << " " << p.x << " " << p.y << " " << Y.x << " " << Y.y << endl;
		}
	}
	return 0;
}

Corrdinates path(Corrdinates X, Corrdinates Y)
{
	Corrdinates tmp = X;
	while(tmp.x > 'A' && tmp.y > 1){
		tmp.x--;
		tmp.y--;
		if(abs(tmp.x - Y.x) == abs(tmp.y - Y.y)) return tmp;
	}
	tmp = X;
	while(tmp.x > 'A' && tmp.y < 8){
		tmp.x--;
		tmp.y++;
		if(abs(tmp.x - Y.x) == abs(tmp.y - Y.y)) return tmp;
	}
	tmp = X;
	while(tmp.x < 'H' && tmp.y > 1){
		tmp.x++;
		tmp.y--;
		if(abs(tmp.x - Y.x) == abs(tmp.y - Y.y)) return tmp;
	}
	tmp = X;
	while(tmp.x < 'H' && tmp.y < 8){
		tmp.x++;
		tmp.y++;
		if(abs(tmp.x - Y.x) == abs(tmp.y - Y.y)) return tmp;
	}
}

bool impossible(Corrdinates X, Corrdinates Y)
{
	if((X.x + X.y - Y.x - Y.y) % 2) return true;
	else return false;
}

inline void use_io_optimizations()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}