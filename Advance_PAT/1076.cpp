#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, l;
int forwards(vector<vector<int> > &followers, int root)
{
	queue<int> f_queue;
	int level = l+1;
	int count = -1;
	f_queue.push(root);
	f_queue.push(-1);
	vector<bool> flags(n, false);
	flags[root] = true;
	while(!f_queue.empty()){
		int id = f_queue.front();
		f_queue.pop();
		if(id != -1){
			count++;
			for(int i = 0; i < followers[id].size(); ++i){
				if(!flags[followers[id][i]]){
					f_queue.push(followers[id][i]);
					flags[followers[id][i]] = true;
				}
			}
		}else{
			level--;
			if(level == 0){
				break;
			}
			if(f_queue.empty()){
				break;
			}else{
				f_queue.push(-1);
			}
		}
	}
	return count;
}
int main()
{
	int m, f;
	cin >> n >> l;
	vector<vector<int> > followers(n, vector<int>());
	for(int i = 0; i < n; ++i){
		cin >> m;
		for(int j = 0; j < m; ++j){
			cin >> f;
			followers[f-1].push_back(i);
		}
	}
	int k, id;
	cin >> k;
	for(int i = 0; i < k; ++i){
		cin >> id;
		cout << forwards(followers, id-1) << endl;
	}
	system("pause");
}