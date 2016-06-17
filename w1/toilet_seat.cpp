/********************************************
* https://open.kattis.com/problems/toilet	*
* Copyright: haihv							*
********************************************/

// Thuat toan: ...
// Do phuc tap: O(1)

#include "iostream"
#include "string"

using namespace std;

int main()
{
	string str;
	cin >> str;
	int res[3];

	res[0] = res[1] = res[2] = 0;
	if(str[0] == str[1]){
		if(str[0] != 'U') res[0] = -1;
		else res[1] = -1;
	}
	else{
		if(str[0] == 'U') res[1] = 1;
		else res[0] = 1;
	}
	for(int i = 1; i < str.size(); i++){
		// 1. Up
		if(str[i] != 'U') res[0] += 2;

		// 2. Down
		if(str[i] != 'D') res[1] += 2;

		// 3. Like to find
		if(str[i] != str[i - 1]) res[2]++;
	}

	cout << res[0] << endl << res[1] << endl << res[2] << endl;
	return 0;
}