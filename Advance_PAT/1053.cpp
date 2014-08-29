#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;
struct Node{
	int elem;
	int path;
	long weight;
	bool known;
	Node(int e): elem(e), weight(0), path(-1), known(false) {};
};
int adjmatrix[105][105];
long weight[105];
void dfs(vector<Node>& tree, int idx, int n)
{
	tree[idx].known = true;
	tree[idx].weight += weight[idx];
	for(int i = 0; i < n; ++i){
		if(adjmatrix[idx][i] != 0 && !tree[i].known){
			tree[i].path = idx;
			tree[i].weight = tree[idx].weight;
			dfs(tree, i, n);
		}
	}
}
void getPath(vector<Node>& tree, int idx, vector<int>& paths)
{
	stack<long> weight_s;
	while(tree[idx].path != -1){
		weight_s.push(weight[idx]);
		idx = tree[idx].path;
	}
	weight_s.push(weight[0]);
	while(!weight_s.empty()){
		paths.push_back(weight_s.top());
		weight_s.pop();
	}
}
// if a > b
bool comparePath(const vector<int> a, const vector<int> b)
{
	int m = a.size();
	int n = b.size();
	for(int i = 0, j = 0; i < m && j < n; ++i, ++j){
		if(a[i] != b[j])
			return a[i] > b[j];
	}
	return m > n;
}
int main()
{
	int n, m;
	long s;
	cin >> n >> m >> s;
	vector<Node> tree;
	for(int i = 0; i < n; ++i){
		cin >> weight[i];
		Node node = Node(i);
		tree.push_back(node);
	}
	int childnum[105];
	for(int i = 0; i < 105; ++i){
		childnum[i] = 0;
		for(int j = 0; j < 105; ++j)
			adjmatrix[i][j] = 0;
	}
	int parent, son, num;
	for(int i = 0; i < m; ++i){
		cin >> parent >> num;
		childnum[parent] = num;
		while(num--){
			cin >> son;
			adjmatrix[parent][son] = adjmatrix[son][parent] = 1;
		}
	}
	dfs(tree, 0, n);
	vector<int> all_paths[105];
	int idx = 0;
	for(int i = 0; i < n; ++i){
		vector<int> paths;
		if(childnum[i] == 0 && tree[i].weight == s){
			getPath(tree, i, paths);
			all_paths[idx++] = paths;
		}
	}
	sort(all_paths, all_paths+idx, comparePath);
	for(int i = 0; i < idx; ++i){
		cout << all_paths[i][0];
		for(int j = 1; j < all_paths[i].size(); ++j){
			cout << " " << all_paths[i][j];
		}
		cout << endl;
	}
	system("pause");
}