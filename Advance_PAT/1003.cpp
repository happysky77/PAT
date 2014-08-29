#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	vector<vector<int> > dists;
	vector<bool> visited(n, false);
	for(int i = 0; i < n; ++i){
		dists.push_back(vector<int>(n, 0));
	}
	vector<int> teams(n, 0);
	for(int i = 0; i < n; ++i){
		cin >> teams[i];
	}
	int s, d, l;
	for(int i = 0; i < m; ++i){
		cin >> s >> d >> l;
		dists[s][d] = dists[d][s] = l;
	}
	vector<int> shortest(n, INT_MAX);
	vector<int> maxteams(n, 0);
	vector<int> count(n, 0);
	shortest[c1] = 0;
	visited[c1] = true;
	maxteams[c1] = teams[c1];
	count[c1] = 1;
	for(int i = 0; i < n; ++i){
		if(i != c1 && dists[c1][i] && !visited[i]){
			shortest[i] = shortest[c1] + dists[c1][i];
			maxteams[i] = maxteams[c1] + teams[i];
			count[i] = count[c1];
		}
	}
	for(int i = 0; i < n-1; ++i){
		int minidx = 0;
		int mindist = INT_MAX;
		for(int j = 0; j < n; ++j){
			if(!visited[j] && shortest[j] < mindist){
				mindist = shortest[j];
				minidx = j;
			}
		}
		visited[minidx] = true;
		for(int j = 0; j < n; ++j){
			if(!visited[j] &&  dists[minidx][j]){
				int tmpdist = shortest[minidx] + dists[minidx][j];
				if(shortest[j] > tmpdist){
					shortest[j] = tmpdist;
					maxteams[j] = maxteams[minidx] + teams[j];
					count[j] = count[minidx];
				}else if(shortest[j] == tmpdist){
					count[j] += count[minidx];
					if(maxteams[j] < maxteams[minidx] + teams[j]){
						maxteams[j] = maxteams[minidx] + teams[j];
					}
				}
			}
		}
		if(mindist == INT_MAX || minidx == c2){
			break;
		}
	}
	cout << count[c2] << " " << maxteams[c2] << endl;
	system("pause");
}