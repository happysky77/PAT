#include <iostream>
#include <map>
using namespace std;
struct Node{
	int key, address, next;
};
int main(){
	int n, start;
	scanf("%d%d", &n, &start);
	map<int, Node> lists;
	int address, key, next;
	for(int i = 0; i < n; ++i){
		Node node;
		scanf("%d%d%d", &node.address, &node.key, &node.next);
		lists[node.address] = node;
	}
	if(start == -1){
		printf("0 -1\n");
	}else{
		map<int, int> res;
		Node tmp = lists[start];
		while(tmp.next != -1){
			res[tmp.key] = tmp.address;
			tmp = lists[tmp.next];
		}
		res[tmp.key] = tmp.address;
		printf("%d %05d\n", res.size(), res.begin()->second);
		for(auto itr = res.begin(); itr != res.end(); ){
			printf("%05d %d ", itr->second, itr->first);
			itr++;
			if(itr != res.end()){
				printf("%05d\n", itr->second);
			}else{
				printf("-1\n");
			}
		}
	}
	system("pause");
}