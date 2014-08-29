#include <iostream>
#include <unordered_map>
using namespace std;
int findNotOk(unordered_map<int, int> &num, int beg){
	for(int i = beg; i < num.size(); ++i){
		if(num[i] != i){
			return i;
		}
	}
	return 0;
}
int main(){
	int n, num;
	scanf("%d", &n);
	unordered_map<int, int> num_map;
	for(int i = 0; i < n; ++i){
		scanf("%d", &num);
		num_map[num] = i;
	}
	int count = 0;
	int firstPos = 1;
	firstPos = findNotOk(num_map, firstPos);
	while(firstPos){
		if(num_map[0] == 0){
			num_map[0] = num_map[firstPos];
			num_map[firstPos] = 0;
			count++;
		}
		while(num_map[0] != 0){
			int tmp = num_map[0];
			num_map[0] = num_map[tmp];
			num_map[tmp] = tmp;
			count++;
		}
		firstPos = findNotOk(num_map, firstPos);
	}
	printf("%d\n", count);
	system("pause");
}