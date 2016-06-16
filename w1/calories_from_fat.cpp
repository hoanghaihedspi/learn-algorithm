/************************************************
* https://open.kattis.com/problems/calories		*
* Copyright: haihv								*
************************************************/

#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

#define FAT 9
#define PSS 4	// Protein, Sugar, Starch
#define ALCOHOL 7

typedef struct _Calo
{
	double fat;
	double total;
} Calo;

inline void use_io_optimizations();
Calo process(vector<string> r);
void output(vector<Calo> calo);

int main()
{
	use_io_optimizations();

	vector<string> r (5);
	vector<Calo> calo;
	while(1){
		cin >> r[0];
		loop:
		while(r[0] != "-"){
			cin >> r[1] >> r[2] >> r[3] >> r[4];

			calo.push_back(process(r));

			cin >> r[0];
		}

		output(calo);
		calo.resize(0);

		cin >> r[0];
		if(r[0] == "-") return 0;
		else goto loop;
	}
}

void output(vector<Calo> calo)
{
	double ft = 0;
	double t = 0;
	for(vector<Calo>::iterator it = calo.begin(); it != calo.end(); it++){
		ft += it->fat;
		t += it->total;
	}
	if(t == 0) cout << "0%" << endl;
	else cout << round(ft / t) << "%" << endl;
}

Calo process(vector<string> r)
{
	Calo calo;
	double pt = 100, pf = 0;
	double ct = 0, f = 0;

	// Fat
	if(r[0].back() == '%'){ r[0].pop_back(); pf = stod(r[0]); pt -= pf; }
	else if(r[0].back() == 'C'){ r[0].pop_back(); f = stoi(r[0]); ct += f; }
	else if(r[0].back() == 'g'){ r[0].pop_back(); f = FAT * stoi(r[0]); ct += f; }

	// Protein, Sugar, Starch
	for(int i = 1; i <= 3; i++){
		if(r[i].back() == '%'){ r[i].pop_back(); pt -= stod(r[i]); }
		else if(r[i].back() == 'C'){ r[i].pop_back(); ct += stoi(r[i]); }
		else if(r[i].back() == 'g'){ r[i].pop_back(); ct += PSS * stoi(r[i]); }
	}

	// Alcohol
	if(r[4].back() == '%'){ r[4].pop_back(); pt -= stod(r[4]); }
	else if(r[4].back() == 'C'){ r[4].pop_back(); ct += stoi(r[4]); }
	else if(r[4].back() == 'g'){ r[4].pop_back(); ct += ALCOHOL * stoi(r[4]); }

	calo.total = ( pt == 0 ? 100 : ct / pt );
	calo.fat = ( pf == 0 ? f : calo.total * pf );

	return calo;
}

inline void use_io_optimizations()
{
	ios_base::sync_with_stdio();
	cin.tie();
}