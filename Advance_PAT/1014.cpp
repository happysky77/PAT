#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
	int n, m, k, q;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	vector<int> costs(k, 0);
	for(int i = 0; i < k; ++i){
		scanf("%d", &costs[i]);
	}
	vector<int> queries(q, 0);
	for(int i = 0; i < q; ++i){
		scanf("%d", &queries[i]);
	}
	vector<int> leaveTime(k, 0);
	queue<int> windows[25];
	vector<int> timeBase(25,0);
	int idx = 0;
	for(; idx < n*m && idx < k; ++idx){
		windows[idx%n].push(idx);
		leaveTime[idx] = timeBase[idx%n] + costs[idx];
		timeBase[idx%n] = leaveTime[idx];
	}
	for(; idx < k; ++idx){
		int fastTime = INT_MAX;
		int fastWin = 0;
		for(int i = 0; i < n; ++i){
			int id = windows[i].front();
			if(leaveTime[id] < fastTime){
				fastTime = leaveTime[id];
				fastWin = i;
			}
		}
		windows[fastWin].pop();
		windows[fastWin].push(idx);
		leaveTime[idx] = timeBase[fastWin] + costs[idx];
		timeBase[fastWin] = leaveTime[idx];
	}
	for(auto itr = queries.begin(); itr != queries.end(); ++itr){
		if(leaveTime[*itr-1] - costs[*itr-1] >= 540){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n", leaveTime[*itr-1]/60+8, leaveTime[*itr-1]%60);
		}
	}
	system("pause");
}