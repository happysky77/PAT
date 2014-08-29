#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int main()
{
	int k1, k2, n;
	cin >> k1;
	map<int, double> anum, bnum, res;
	double a;
	for(int i = 0; i < k1; ++i){
		cin >> n >> a;
		anum[n] = a;
	}
	cin >> k2;
	for(int i = 0; i < k2; ++i){
		cin >> n >> a;
		bnum[n] = a;
	}
	for(auto aitr = anum.begin(); aitr != anum.end(); ++aitr){
		for(auto bitr = bnum.begin(); bitr != bnum.end(); ++bitr){
			res[aitr->first + bitr->first] += aitr->second * bitr->second;
		}
	}
	int count = 0;
	for(auto itr = res.rbegin(); itr != res.rend(); ++itr){
		if(fabs(itr->second) > 1e-6){
			count++;
		}
	}
	cout << count;
	for(auto itr = res.rbegin(); itr != res.rend(); ++itr){
		if(fabs(itr->second) > 1e-6){
			printf(" %d %.1f", itr->first, itr->second);
		}
	}
	cout << endl;
	system("pause");
}