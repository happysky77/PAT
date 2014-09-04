#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int cm, n, sp, m;
vector<vector<int> > parents;
vector<int> paths;
vector<int> res;
vector<int> cities;
int minSend = INT_MAX;
int minCollect = INT_MAX;
void findBestPath(int u){
	paths.push_back(u);
	if(u == 0){
		int tmpSend = 0;
		int tmpCollect = 0;
		for(int j = paths.size()-1; j >= 0; --j){
			if(cities[paths[j]] > cm/2){
				tmpCollect += cities[paths[j]] - cm/2;
			}else if(cities[paths[j]] < cm/2){
				tmpCollect -= cm/2 - cities[paths[j]];
				if(tmpCollect < 0){
					tmpSend -= tmpCollect;
					tmpCollect = 0;
				}
			}
		}
		if(tmpSend < minSend){
			minSend = tmpSend;
			minCollect = tmpCollect;
			res = paths;
		}else if(tmpSend == minSend && tmpCollect < minCollect){
			minCollect = tmpCollect;
			res = paths;
		}
		return;
	}
	for(int i = 0; i < parents[u].size(); ++i){
		findBestPath(parents[u][i]);
		paths.pop_back();
	}
}
void dikstra(vector<vector<int> >& dists){
	parents.clear();
	parents.resize(n+1);
	vector<bool> visited(n+1, false);
	vector<int> shortest(n+1, INT_MAX);
	for(int i = 1; i <= n; ++i){
		if(dists[0][i]){
			shortest[i] = dists[0][i];
			parents[i].push_back(0);
		}else{
			parents[i].push_back(-1);
		}
	}
	shortest[0] = 0;
	visited[0] = true;
	for(int i = 1; i < n; ++i){
		int mindist = INT_MAX;
		int minidx = 1;
		for(int j = 1; j <= n; ++j){
			if(!visited[j] && shortest[j] < mindist){
				mindist = shortest[j];
				minidx = j;
			}
		}
		visited[minidx] = true;
		if(minidx == sp){
			break;
		}
		for(int j = 1; j <= n; ++j){
			if(!visited[j] && dists[minidx][j]){
				if(shortest[j] > shortest[minidx] + dists[minidx][j]){
					parents[j].clear();
					parents[j].push_back(minidx);
					shortest[j] = shortest[minidx] + dists[minidx][j];
				}else if(shortest[j] == shortest[minidx] + dists[minidx][j]){
					parents[j].push_back(minidx);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d", &cm, &n, &sp, &m);
	cities.resize(n+1);
	cities[0] = cm/2;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &cities[i]);
	}
	int s, d, l;
	vector<vector<int> > dists;
	for(int i = 0; i < n+1; ++i)
		dists.push_back(vector<int>(n+1, 0));
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d", &s, &d, &l);
		dists[s][d] = dists[d][s] = l;
	}
	dikstra(dists);
	findBestPath(sp);
	printf("%d 0", minSend);
	res.pop_back();
	for(auto itr = res.rbegin(); itr != res.rend(); ++itr){
		printf("->%d", *itr);
	}
	printf(" %d\n", minCollect);
	system("pause");
}