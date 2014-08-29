#include <iostream>
#include <map>
using namespace std;
int main()
{
	double c, d, davg, n;
	cin >> c >> d >> davg >> n;
	map<double, double> price_dists;
	double price, dist;
	for(int i = 0; i < n; ++i){
		cin >> price >> dist;
		price_dists[dist] = price;
	}
	double prices = 0.0f;
	bool flag = false; // false: empty, true: remain
	double remain = 0.0f;
	bool isMaxDist = true;
	auto itr = price_dists.begin();
	if(itr->first > 0.0){
		printf("The maximum travel distance = 0.00\n");
		system("pause");
		return 0;
	}
	auto last = itr;
	while(itr != price_dists.end()){
		if(flag){
			remain = c - (itr->first - last->first) / davg;
		}else{
			remain = 0.0f;
		}
		double maxdist = itr->first + davg * c;
		maxdist = min(maxdist, d);
		auto pitr = itr;
		pitr++;
		if(pitr == price_dists.end()){
			break;
		}
		if(pitr->first > maxdist){
			if(maxdist < d){
				printf("The maximum travel distance = %.2f\n", maxdist);
				isMaxDist = false;
				break;
			}else{
				prices += itr->second * maxdist / davg;
				printf("%.2f\n", prices);
				isMaxDist = false;
				break;
			}
		}else{
			while(pitr != price_dists.end() && pitr->first <= maxdist){
				if(pitr->second <= itr->second){
					prices += itr->second * ((pitr->first - itr->first) / davg - remain);
					last = itr;
					itr = pitr;
					flag = false;
					break;
				}
				pitr++;
			}
			// prices > current price
			if(itr != pitr){
				last = itr;
				prices += itr->second * (c - remain);
				itr++;
				double minprice = itr->second;
				auto nextitr = itr;
				while(itr != pitr){
					if(itr->second < minprice){
						nextitr = itr;
						minprice = itr->second;
					}
					itr++;
				}
				itr = nextitr;
				flag = true;
			}
		}
	}
	if(isMaxDist){
		double maxdist = itr->first + davg * c;
		if(d <= maxdist){
			prices += itr->second * ((d - itr->first) / davg - remain);
			printf("%.2f\n", prices);
		}else{
			printf("The maximum travel distance = %.2f\n", maxdist);
		}
	}
	system("pause");
}