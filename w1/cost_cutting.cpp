#include "iostream"

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int x, y, z, res;
		cin >> x >> y >> z;
		if((x - y) * (x - z) < 0) res = x;
		else if((y - x) * (y - z) < 0) res = y;
		else res = z;
		cout << "Case " << i + 1 << ": " << res << endl;
	}

	return 0;
}