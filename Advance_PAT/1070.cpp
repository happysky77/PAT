#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Cake{
	double inventory;
	double price;
	Cake(double in, double p) : inventory(in), price(p) {}
};
bool compare(const Cake a, const Cake b)
{
	return (a.price / a.inventory) > (b.price / b.inventory);
}
int main()
{
	//把inventory换成double类型，就答案正确了，否则有一个case答案错误。。。
	int n;
	double demand;
	cin >> n >> demand;
	double inventorys[1005];
	double prices[1005];
	for(int i = 0; i < n; ++i)
		cin >> inventorys[i];
	for(int i = 0; i < n; ++i)
		cin >> prices[i];
	vector<Cake> cakes;
	for(int i = 0; i < n; ++i){
		Cake c = Cake(inventorys[i], prices[i]);
		cakes.push_back(c);
	}
	sort(cakes.begin(), cakes.end(), compare);
	double sum = 0.0;
	double profit = 0.0;
	for(double i = 0; i < cakes.size(); ++i){
		if(sum + cakes[i].inventory < demand){
			profit += cakes[i].price;
			sum += cakes[i].inventory;
		} else {
			profit += cakes[i].price * ((demand - sum) / cakes[i].inventory);
			break;
		}
	}
	printf("%.2f\n", profit);
	system("pause");
}