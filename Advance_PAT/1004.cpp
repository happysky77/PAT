#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int val;
	Node* firstChild;
	Node* sibling;
	Node(int v): val(v) {firstChild = sibling = NULL;}
};
void couting(Node* root){
	queue<Node*> node_que;
	node_que.push(root);
	node_que.push(NULL);
	int count = 0;
	while(!node_que.empty()){
		Node* tmp = node_que.front();
		node_que.pop();
		if(tmp == NULL){
			if(node_que.empty()){
				cout << count << endl;
			}else{
				cout << count << " ";
				count = 0;
				node_que.push(NULL);
			}
		}else{
			if(tmp->firstChild){
				Node* child = tmp->firstChild;
				while(child){
					node_que.push(child);
					child = child->sibling;
				}
			}else{
				count++;
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<Node*> node_vec;
	for(int i = 0; i < n; ++i){
		node_vec.push_back(new Node(i+1));
	}
	int parent, k, child, pre;
	for(int i = 0; i < m; ++i){
		cin >> parent >> k >> pre;
		node_vec[parent-1]->firstChild = node_vec[pre-1];
		for(int j = 1; j < k; ++j){
			cin >> child;
			node_vec[pre-1]->sibling = node_vec[child-1];
			pre = child;
		}
	}
	couting(node_vec[0]);
	system("pause");
}