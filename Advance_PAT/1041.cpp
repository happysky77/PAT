#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
	int n, num;
	scanf("%d", &n);
	unordered_map<int, bool> flags;
	vector<int> num_vec;
	while(n--){
		scanf("%d", &num);
		num_vec.push_back(num);
		if(flags.find(num) == flags.end()){
			flags[num] = true;
		}else{
			flags[num] = false;
		}
	}
	bool flag = false;
	for(auto itr = num_vec.begin(); itr != num_vec.end(); ++itr){
		if(flags[*itr] == true){
			flag = true;
			printf("%d\n", *itr);
			break;
		}
	}
	if(!flag){
		printf("None\n");
	}
	system("pause");
}