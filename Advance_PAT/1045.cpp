#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, k, color;
	cin >> n;
	cin >> m;
	vector<int> favors;
	for(int i = 0; i < m; ++i){
		cin >> color;
		favors.push_back(color);
	}
	cin >> k;
	vector<int> colors;
	for(int i = 0; i < k; ++i){
		cin >> color;
		if(find(favors.begin(), favors.end(), color) != favors.end()){
			colors.push_back(color);
		}
	}
	reverse(colors.begin(), colors.end());
	vector<int> nums(favors.size(), 0);
	for(int i = 0; i < colors.size(); ++i){
		auto itr = find(favors.begin(), favors.end(), colors[i]);
		int len = itr - favors.begin();
		nums[len]++;
		for(int j = 0; j < len; ++j){
			nums[j] = max(nums[j], nums[len]);
		}
	}
	cout << nums[0] << endl;
	system("pause");
}