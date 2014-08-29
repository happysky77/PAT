#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long nc, np;
	vector<long> pos_coup;
	vector<long> neg_coup;
	vector<long> pos_prod;
	vector<long> neg_prod;
	cin >> nc;
	long coup;
	while(nc--){
		cin >> coup;
		if(coup > 0)
			pos_coup.push_back(coup);
		else if(coup < 0)
			neg_coup.push_back(coup);
	}
	cin >> np;
	long prod;
	while(np--){
		cin >> prod;
		if(prod > 0)
			pos_prod.push_back(prod);
		else if(prod < 0)
			neg_prod.push_back(prod);
	}
	sort(pos_coup.begin(), pos_coup.end());
	sort(pos_prod.begin(), pos_prod.end());
	int sum = 0;
	int len1, len2;
	len1 = pos_coup.size();
	len2 = pos_prod.size();
	for(int i = len1-1, j = len2-1; i >= 0 && j >= 0; --i, --j){
		sum += pos_coup[i] * pos_prod[j];
	}
	sort(neg_coup.begin(), neg_coup.end());
	sort(neg_prod.begin(), neg_prod.end());
	int len3, len4;
	len3 = neg_coup.size();
	len4 = neg_prod.size();
	for(int i = 0, j = 0; i < len3 && j < len4; ++i, ++j){
		sum += neg_coup[i] * neg_prod[j];
	}
	cout << sum << endl;
	system("pause");
}