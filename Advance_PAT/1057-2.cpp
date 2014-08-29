#include <iostream>
#include <stack>
#include <stdio.h>  
#include <cstring>
#include <set>
using namespace std;
const int N = 100005;
int mid;
multiset<int> minm, maxm;
stack<int> num_stack;
void adjust()
{
	multiset<int>::iterator it;
	if(maxm.size() + 1 < minm.size()){
		it = minm.end();
		it--;
		maxm.insert(*it);
		minm.erase(it);
	}else if(maxm.size() > minm.size()){
		it = maxm.begin();
		minm.insert(*it);
		maxm.erase(it);
	}
	if(num_stack.size() > 0){
		it = minm.end();
		it--;
		mid = *it;
	}
}
int main(){
	int n, pos;
	scanf("%d", &n);
	char str[20];
	multiset<int>::iterator it;
	mid = -1;
	while(n--){
		scanf("%s", str);
		if(str[1] == 'u'){
			scanf("%d", &pos);
			num_stack.push(pos);
			if(num_stack.empty()){
				minm.insert(pos);
				mid = pos;
			}else if(pos <= mid){
				minm.insert(pos);
			}else{
				maxm.insert(pos);
			}
			adjust();
		}else if(str[1] == 'o'){
			if(num_stack.empty()){
				printf("Invalid\n");
			}else{
				pos = num_stack.top();
				num_stack.pop();
				printf("%d\n", pos);
				if(mid >= pos){
					it = minm.find(pos);
					minm.erase(it);
				}else{
					it = maxm.find(pos);
					maxm.erase(it);
				}
				adjust();
			}
		}else if(str[1] == 'e'){
			if(num_stack.empty()){
				printf("Invalid\n");
			}else{
				printf("%d\n", mid);
			}
		}else{
			printf("Invalid\n");
		}
	}
	system("pause");
}