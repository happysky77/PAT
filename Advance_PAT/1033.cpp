#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h>
using namespace std;
struct Gas{
	double price, dist;
	bool operator< (const Gas& g) const{
		return dist < g.dist;
	}
};
int main()
{
	double c, d, davg, n;
	cin >> c >> d >> davg >> n;
	vector<Gas> gass;
	double price, dist;
	for(int i = 0; i < n; ++i){
		Gas gas;
		cin >> gas.price >> gas.dist;
		gass.push_back(gas);
	}
	sort(gass.begin(), gass.end());
	if(gass.size() == 0 || gass[0].dist > 0.0){
		printf("The maximum travel distance = 0.00\n");
		system("pause");
		return 0;
	}

	bool flag = false; // whether arrive at the destination
	double prices = 0.0f;
	double remain = 0.0f;
	int index = 0;
	double maxdist = davg * c;
	while(!flag){
		bool tag = false; // whether has gas among maxdist
		bool isCheaper = false; // whether has cheaper gas
		double cheapest = DBL_MAX;
		int cheapIdx = index;
		for(int i = index+1; i < n; ++i){
			if(gass[i].dist <= gass[index].dist + maxdist){
				tag = true;
				if(gass[i].price < gass[index].price){
					isCheaper = true;
					prices += ((gass[i].dist - gass[index].dist) / davg - remain) * gass[index].price;
					remain = 0.0f;
					index = i;
					break;
				}
				if(gass[i].price < cheapest){
					cheapest = gass[i].price;
					cheapIdx = i;
				}
			}else{
				break;
			}
		}
		if(!isCheaper && gass[index].dist + maxdist >= d){ 
			prices += (d - gass[index].dist) / davg * gass[index].price;
			printf("%.2f\n", prices);
			system("pause");
			return 0;
		}
		if(!isCheaper && tag){
			prices += (c - remain) * gass[index].price;
			remain = c - (gass[cheapIdx].dist - gass[index].dist) / davg;
			index = cheapIdx;
		}else if(!tag){
			printf("The maximum travel distance = %.2lf\n", gass[index].dist + maxdist);
			system("pause");
			return 0;
		}
	}
}