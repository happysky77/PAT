#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, dist, m, s, d;
	cin >> n;
	vector<int> dists(n+1, 0);
	int total = 0;
	for(int i = 0; i < n; ++i){
		cin >> dist;
		total += dist;
		if(i == 0){
			dists[i+1] = dist;
		}else{
			dists[i+1] = dists[i] + dist;
		}
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		cin >> s >> d;
		if(s > d){
			int tmp = s;
			s = d;
			d = tmp;
		}
		int mid = dists[d-1] - dists[s-1];
		cout << min(mid, total-mid) << endl;
	}
	system("pause");
}