#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n;
vector<vector<int> > connected;
vector<int> parents;
vector<int> dists;
vector<bool> visited;
int BFS(int s){
	visited.assign(n+1, false);
	dists.assign(n+1, 0);
	queue<int> que;
	que.push(s);
	visited[s] = true;
	int mmax = dists[s];
	int cnt = 1;
	while(!que.empty()){
		int c = que.front();
		que.pop();
		for(int i = 0; i < connected[c].size(); ++i){
			int v = connected[c][i];
			if(!visited[v]){
				dists[v] = dists[c] + 1;
				que.push(v);
				mmax = max(mmax, dists[v]);
				visited[v] = true;
				cnt++;
				if(cnt == n) break;
			}
		}
	}
	return mmax;
}
void initSet(){
	parents.resize(n+1);
	for(int i = 0; i < parents.size(); ++i)
		parents[i] = i;
}
int findParent(int i){
	if(parents[i] == i){
		return i;
	}else{
		return parents[i] = findParent(parents[i]);
	}
}
int unionSet(int a, int b){
	int pa = findParent(a);
	int pb = findParent(b);
	if(pa == pb){
		return -1; // circle
	}else{
		parents[pa] = pb;
		return 0;
	}
}
int main(){
	int from, to;
	scanf("%d", &n);
	initSet();
	bool isCycle = false;
	connected.resize(n+1);
	for(int i = 0; i < n-1; ++i){
		scanf("%d%d", &from, &to);
		connected[from].push_back(to);
		connected[to].push_back(from);
		if(unionSet(from, to)){
			isCycle = true;
		}
	}
	set<int> roots;
	for(int i = 1; i <= n; ++i){
		roots.insert(findParent(i));
	}
	if(isCycle || roots.size() > 1){
		printf("Error: %d components\n", roots.size());
	}else{
		set<int> candidates;
		int mmax = BFS(1);
		for(int i = 1; i <= n; ++i){
			if(dists[i] == mmax) candidates.insert(i);
		}
		mmax = BFS(*candidates.begin());
		for(int i = 1; i <= n; ++i){
			if(dists[i] == mmax) candidates.insert(i);
		}
		for(auto itr = candidates.begin(); itr != candidates.end(); ++itr)
			printf("%d\n", *itr);
	}
	system("pause");
}