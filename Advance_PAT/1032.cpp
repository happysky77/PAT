#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
	int start1, start2, t;
	scanf("%d%d%d", &start1, &start2, &t);
	unordered_map<int,int> address_map;
	int cur, next;
	char ch;
	for(int i = 0; i < t; ++i){
		scanf("%d", &cur);
		getchar();
		ch = getchar();
		getchar();
		scanf("%d", &next);
		address_map[cur] = next;
	}
	vector<int> list1;
	cur = start1;
	while(cur != -1){
		list1.push_back(cur);
		cur = address_map[cur];
	}
	vector<int> list2;
	cur = start2;
	while(cur != -1){
		list2.push_back(cur);
		cur = address_map[cur];
	}
	int m = list1.size();
	int n = list2.size();
	int idx1, idx2;
	idx1 = idx2 = 0;
	if(m > n){
		idx1 = m - n;
	}else{
		idx2 = n - m;
	}
	bool isFound = false;
	while(idx1 < list1.size() && idx2 < list2.size()){
		if(list1[idx1] == list2[idx2]){
			isFound = true;
			printf("%05d\n", list1[idx1]);
			break;
		}
		idx1++;
		idx2++;
	}
	if(!isFound){
		printf("-1\n");
	}
	system("pause");
}