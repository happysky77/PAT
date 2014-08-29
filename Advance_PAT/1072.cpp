#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int n, m, k, ds;
bool dijkstra(vector<vector<int> > &dist, const int start, int& mdist, int& sumdist)
{
	int t = n+m;
	vector<int> shortest(t, INT_MAX);
	vector<bool> visited(t, false);
	for(int i = 0; i < t; ++i){
		if(dist[start][i]){
			shortest[i] = dist[start][i];
		}
	}
	shortest[start] = 0;
	visited[start] = true;
	for(int i = 1; i < t; ++i){
		int mindist = INT_MAX;
		int minidx = 0;
		for(int j = 0; j < t; ++j){
			if(!visited[j] && shortest[j] < mindist){
				mindist = shortest[j];
				minidx = j;
			}
		}
		visited[minidx] = true;
		//if(shortest[minidx] > ds){
		//	return false;
		//}
		for(int j = 0; j < t; ++j){
			if(!visited[j] && dist[minidx][j] && shortest[j] > shortest[minidx] + dist[minidx][j]){
				shortest[j] = shortest[minidx] + dist[minidx][j];
			}
		}
	}
	mdist = INT_MAX;
	sumdist = 0;
	for(int i = 0; i < n; ++i){
		if(shortest[i] > ds){
			return false;
		}
		if(shortest[i] < mdist){
			mdist = shortest[i];
		}
		sumdist += shortest[i];
	}
	return true;
}
int main(){
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	vector<vector<int> > dists;
	int t = n+m;
	for(int i = 0; i < t; ++i){
		dists.push_back(vector<int>(t, 0));
	}
	char p1[10];
	char p2[10];
	char dd[10];
	int pp1, pp2, dist;
	for(int i = 0; i < k; ++i){
		scanf("%s%s%s", p1, p2, dd);
		if(p1[0] == 'G'){
			pp1 = atoi(p1+1) + n;
		}else{
			pp1 = atoi(p1);
		}
		if(p2[0] == 'G'){
			pp2 = atoi(p2+1) + n;
		}else{
			pp2 = atoi(p2);
		}
		dist = atoi(dd);
		dists[pp1-1][pp2-1] = dists[pp2-1][pp1-1] = dist;
	}
	vector<int> mdists(m, 0);
	vector<int> sumdists(m, 0);
	bool isFind = false;
	int idx = -1;
	int maxdist = INT_MIN;
	int minavg = INT_MAX;
	for(int i = 0; i < m; ++i){
		bool flag = dijkstra(dists, n+i, mdists[i], sumdists[i]);
		if(flag){
			isFind = true;
			if(mdists[i] > maxdist){
				maxdist = mdists[i];
				minavg = sumdists[i];
				idx = i;
			}else if(mdists[i] == maxdist && sumdists[i] < minavg){
				minavg = sumdists[i];
				idx = i;
			}
		}
	}
	if(isFind){
		printf("G%d\n", idx+1);
		printf("%.1f %.1f\n", 1.0*maxdist, 1.0*minavg/n);
	}else{
		printf("No Solution\n");
	}
	system("pause");
}