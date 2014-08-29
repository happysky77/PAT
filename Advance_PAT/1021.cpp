#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, from, to;
	scanf("%d", &n);
	vector<pair<int, int> > connected;
	vector<pair<int, int> > depth_vec;
	for(int i = 0; i < n-1; ++i){
		scanf("%d%d", &from, &to);
		connected.push_back(pair<int, int>(from, to));
		connected.push_back(pair<int,int>(to, from));
	}
	bool flag = true;
	int maxdepth = 0;
	for(int i = 1; i <= n; ++i){
		int dep = 0;
		int component = 0;
		int remain = n;

		vector<bool> visited(n+1, false);
		while(remain){
			queue<int> que_node;
			if(component){
				for(int k = 1; k <= n; ++k){
					if(visited[k] == false){
						i = k;
						break;
					}
				}
			}
			que_node.push(i);
			que_node.push(0);
			while(!que_node.empty()){
				int tmp = que_node.front();
				que_node.pop();
				if(tmp){
					if(visited[tmp]){ // cycle
						continue;
					}
					visited[tmp] = true;
					remain--;
					for(int j = 1; j <= n; ++j){
						if(!visited[j]){
							auto itr = find(connected.begin(), connected.end(), pair<int, int>(tmp, j));
							if(itr != connected.end()){
								que_node.push(j);
							}
						}
					}
				}else{
					if(!que_node.empty()){
						que_node.push(0);
						dep++;
					}else{
						break;
					}
				}
			}
			depth_vec.push_back(pair<int, int>(i, dep));
			if(dep > maxdepth){
				maxdepth = dep;
			}
			component++;
		}
		if(component > 1){
			printf("Error: %d components\n", component);
			flag = false;
			break;
		}
	}
	if(flag){
		for(auto itr = depth_vec.begin(); itr != depth_vec.end(); ++itr){
			if(itr->second == maxdepth){
				printf("%d\n", itr->first);
			}
		}
	}
	system("pause");
}