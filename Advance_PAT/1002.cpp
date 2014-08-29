#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int k1, k2, e;
	scanf("%d", &k1);
	double coef;
	map<int, double> num1_map;
	map<int, double> num2_map;
	for(int i = 0; i < k1; ++i){
		scanf("%d %lf", &e, &coef);
		num1_map[e] = coef;
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; ++i){
		scanf("%d %lf", &e, &coef);
		num2_map[e] = coef;
	}
	auto itr1 = num1_map.rbegin();
	auto itr2 = num2_map.rbegin();
	vector<pair<int,double> > res;
	while(itr1 != num1_map.rend() && itr2 != num2_map.rend()){
		if(itr1->first > itr2->first){
			res.push_back(pair<int, double>(itr1->first, itr1->second));
			itr1++;
		}else if(itr1->first < itr2->first){
			res.push_back(pair<int, double>(itr2->first, itr2->second));
			itr2++;
		}else{
			double tmp = itr1->second + itr2->second;
			if(fabs(tmp) > 1e-6){
				res.push_back(pair<int, double>(itr1->first, tmp));
			}
			itr1++;
			itr2++;
		}
	}
	while(itr1 != num1_map.rend()){
		res.push_back(pair<int, double>(itr1->first, itr1->second));
		itr1++;
	}
	while(itr2 != num2_map.rend()){
		res.push_back(pair<int, double>(itr2->first, itr2->second));
		itr2++;
	}
	printf("%d", res.size());
	for(auto itr = res.begin(); itr != res.end(); ++itr){
		printf(" %d %.1f", itr->first, itr->second);
	}
	printf("\n");
	system("pause");
}