#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
	int address, id, nextad;
};
int main(){
	int start, n, k;
	scanf("%d%d%d", &start, &n, &k);
	unordered_map<int, Node> address_node;
	int address, id, next;
	for(int i = 0; i < n; ++i){
		Node node;
		scanf("%d%d%d", &node.address, &node.id, &node.nextad);
		address_node[node.address] = node;
	}
	vector<Node> list;
	while(start != -1){
		list.push_back(address_node[start]);
		start = address_node[start].nextad;
	}
	int m = list.size() / k;
	for(int i = 0; i < m; ++i){
		int start = i*k;
		int end = (i+1)*k;
		reverse(list.begin()+start, list.begin()+end);
	}
	for(int i = 0; i < list.size()-1; ++i){
		printf("%05d %d %05d\n", list[i].address, list[i].id, list[i+1].address);
	}
	printf("%05d %d -1\n", list[list.size()-1].address, list[list.size()-1].id);
	return 0;
}