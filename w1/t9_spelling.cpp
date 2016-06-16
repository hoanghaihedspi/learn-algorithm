/****************************************************************************
* https://open.kattis.com/problems/t9spelling								*
* Copyright: haihv															*
****************************************************************************/


#include "iostream"
#include "string"

#define SIZE 27

using namespace std;

int find_index(char c[], char target);

int main()
{
	char character[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	string code[] = {"0", "2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};

	int n;
	cin >> n;
	cin.ignore(1);
	for(int i = 0; i < n; i++){
		string str, res;
		getline(cin, str);
		char prev = -1;
		int index;
		for(int j = 0; j < str.size(); j++){
			index = find_index(character, str[j]);
			if(code[index][0] == prev) res += " " + code[index];
			else res += code[index];
			prev = code[index][0];
		}
		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}

int find_index(char c[], char target)
{
	int l = 0, r = SIZE - 1;
	int t = (l + r) / 2;
	while(l <= r){
		if(c[t] == target) return t;
		else if(c[t] > target) r = t - 1;
		else l = t + 1;
		t = (l + r) / 2;
	}
	return -1;
}