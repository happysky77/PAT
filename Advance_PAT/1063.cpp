#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<set<int> > set_vec;
	for(int i = 0; i < n; ++i){
		int m, num;
		scanf("%d", &m);
		vector<int> num_set;
		for(int j = 0; j < m; ++j){
			scanf("%d", &num);
			num_set.push_back(num);
		}
		sort(num_set.begin(), num_set.end());
		set_vec.push_back(set<int>(num_set.begin(), num_set.end()));
	}
	int k, s1, s2;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d %d", &s1, &s2);
		int size = set_vec[s1-1].size() + set_vec[s2-1].size();
		vector<int> set_u(size, 0);
		vector<int> set_i(size, 0);
		auto itr = set_union(set_vec[s1-1].begin(), set_vec[s1-1].end(), set_vec[s2-1].begin(), set_vec[s2-1].end(), set_u.begin());
		set_u.resize(itr - set_u.begin());
		itr = set_intersection(set_vec[s1-1].begin(), set_vec[s1-1].end(), set_vec[s2-1].begin(), set_vec[s2-1].end(), set_i.begin());
		set_i.resize(itr - set_i.begin());
		printf("%.1f%%\n", 1.0*set_i.size()/set_u.size()*100);
	}
	system("pause");
}