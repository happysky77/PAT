#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
	int address, id, nextad;
	Node* next;
	Node(int i): id(i) {address = nextad = 0; next = NULL;}
};
int main(){
	int start, n, k;
	scanf("%d%d%d", &start, &n, &k);
	unordered_map<int, Node*> address_node;
	int address, id, next;
	for(int i = 0; i < n; ++i){
		scanf("%d%d%d", &address, &id, &next);
		Node* node = new Node(id);
		node->address = address;
		node->nextad = next;
		address_node[address] = node;
	}

	Node* head = address_node[start];
	Node* tmp = head;
	while(tmp->nextad != -1){
		tmp->next = address_node[tmp->nextad];
		tmp = tmp->next;
	}

	tmp = head;
	Node* newhead, *tmphead, *last, *pre;
	newhead = NULL;
	for(int i = 0; i < n/k; ++i){
		pre = tmphead = tmp;
		tmp = tmp->next;
		for(int j = 1; j < k; ++j){
			Node* p = tmp->next;
			tmp->next = tmphead;
			tmphead = tmp;
			tmp = p;
		}
		if(newhead == NULL){
			newhead = tmphead;
		}else{
			last->next = tmphead;
		}
		last = pre;
	}
	if(tmp){
		last->next = tmp;
	}else{
		last->next = NULL;
	}
	tmp = newhead;
	while(tmp){
		if(tmp->next){
			printf("%05d %d %05d\n", tmp->address, tmp->id, tmp->next->address);
		}else{
			printf("%05d %d -1\n", tmp->address, tmp->id);
		}
		tmp = tmp->next;
	}
	system("pause");
}