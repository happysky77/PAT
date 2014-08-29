#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct Node{
	int* dist_list;
	int* cost_list;
	int dist;
	int cost;
	bool known;
	int path;
	Node(): dist(-1), cost(-1), known(false), path(-1), dist_list(NULL), cost_list(NULL) {};
	Node(int* dist_arr, int* cost_arr):  dist(-1), cost(-1), known(false), path(-1), dist_list(dist_arr), cost_list(cost_arr) {};
};
typedef struct vector<Node> Graph;
int findMinDist(Graph& g)
{
	vector<int> d;
	for(int i = 0; i < g.size(); ++i){
		if(g[i].known == false && g[i].dist != -1){
			d.push_back(g[i].dist);
		}
	}
	int idx = -1;
	if(d.empty())
		return idx;
	sort(d.begin(), d.end());
	int min = d[0];
	for(int i = 0; i < g.size(); ++i){
		if(g[i].known == false && g[i].dist == d[0]){
			idx = i;
			break;
		}
	}
	return idx;
}
void dijkstra(Graph& g, int src)
{
	g[src].dist = 0;
	g[src].cost = 0;
	while(true){
		int idx = findMinDist(g);
		if(idx == -1)
			break;
		Node& n = g[idx];
		n.known = true;
		int len = g.size();
		for(int i = 0; i < len; i++){
			if(n.dist_list[i] != 0 && g[i].known == false){
				if(g[i].dist == -1 || (n.dist + n.dist_list[i] < g[i].dist) ){
					g[i].dist = n.dist + n.dist_list[i];
					g[i].cost = n.cost + n.cost_list[i];
					g[i].path = idx;
				} else if ( (n.dist + n.dist_list[i] == g[i].dist) && (n.cost + n.cost_list[i] < g[i].cost) ){
					g[i].cost = n.cost + n.cost_list[i];
					g[i].path = idx;
				}
			}
		}
	}
}
int main()
{
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	int** dist_matrix = new int*[n];
	int** cost_matrix = new int*[n];
	for(int i = 0; i < n; i++){
		dist_matrix[i] = new int[n];
		cost_matrix[i] = new int[n];
		for(int j = 0; j < n; ++j){
			dist_matrix[i][j] = 0;
			cost_matrix[i][j] = 0;
		}
	}
	int src, dest, dist, cost;
	for(int i = 0; i < m; ++i){
		cin >> src >> dest >> dist >> cost;
		dist_matrix[src][dest] = dist;
		dist_matrix[dest][src] = dist;
		cost_matrix[src][dest] = cost;
		cost_matrix[dest][src] = cost;
	}
	Graph graph;
	for(int i = 0; i < n; ++i){
		Node node;
		node.dist_list = dist_matrix[i];
		node.cost_list = cost_matrix[i];
		graph.push_back(node);
	}
	dijkstra(graph, s);
	stack<int> ss;
	int dd = d;
	ss.push(d);
	while(d != s){
		ss.push(graph[d].path);
		d = graph[d].path;
	}
	while(!ss.empty()){
		cout << ss.top() << " ";
		ss.pop();
	}
	cout << graph[dd].dist << " " << graph[dd].cost << endl;
	system("pause");
}