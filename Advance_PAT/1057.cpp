#include <iostream>
#include <stack>
#include<stdio.h>  
#include<cstring>
using namespace std;
const int N = 100005;
int c[N];
// 2^k, k是i末尾连续0的个数
int lowbit(int i){
	return i&(-i);
}
void add(int pos, int value){
	while(pos <	N){
		c[pos] += value;
		pos += lowbit(pos);
	}
}
int sum(int pos){
	int res = 0;
	while(pos > 0){
		res += c[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int find(int value){
	int l = 0, r = N-1, median, res;
	while(l < r-1){
		if((l+r)%2 == 0)
			median = (l+r)/2;
		else
			median = (l+r-1)/2;
		res = sum(median);
		if(res < value)
			l = median;
		else
			r = median;
	}
	return l+1;
}
int main(){
	int n, pos;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	char str[20];
	stack<int> num_stack;
	while(n--){
		scanf("%s", str);
		if(str[1] == 'u'){
			scanf("%d", &pos);
			num_stack.push(pos);
			add(pos, 1);
		}else if(str[1] == 'o'){
			if(num_stack.empty()){
				printf("Invalid\n");
			}else{
				printf("%d\n", num_stack.top());
				add(num_stack.top(), -1);
				num_stack.pop();
			}
		}else if(str[1] == 'e'){
			if(num_stack.empty()){
				printf("Invalid\n");
			}else{
				int size = num_stack.size();
				if(size%2 == 0){
					printf("%d\n", find(size/2));
				}else{
					printf("%d\n", find((size+1)/2));
				}
			}
		}else{
			printf("Invalid\n");
		}
	}
	system("pause");
}