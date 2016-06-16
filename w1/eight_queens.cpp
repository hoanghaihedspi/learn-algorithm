/************************************************************
* https://open.kattis.com/problems/8queens					*
* Copyright: haihv											*
************************************************************/

#include "iostream"

using namespace std;

int main()
{
	char index[8][8];
	for(int i = 0; i < 8; i++){
		bool exist = false;
		for(int j = 0; j < 8; j++){
			cin >> index[i][j];
			if(!exist && index[i][j] == '*') exist = true;
			else if(exist && index[i][j] == '*'){ cout << "invalid"; return 0; }
		}
		if(!exist){ cout << "invalid"; return 0; }
	}

	for(int j = 0; j < 8; j++){
		bool exist = false;
		for (int i = 0; i < 8; i++){
			if(index[i][j] == '*' && !exist){
				exist = true;
				int x = i + 1, y = j + 1;
				while(x < 8 && y < 8)
					if(index[x++][y++] == '*'){ cout << "invalid"; return 0; }
				x = i - 1; y = j + 1;
				while(x >= 0 && y < 8)
					if(index[x--][y++] == '*'){ cout << "invalid"; return 0; }
			}
			else if(exist && index[i][j] == '*'){ cout << "invalid"; return 0; }
		}
		if(!exist){ cout << "invalid"; return 0; }
	}

	cout << "valid";
	return 0;
}