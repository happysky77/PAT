#include <iostream>
#include <vector>
using namespace std;
int main(){
	int k, num;
	scanf("%d", &k);
	vector<int> num_vec(k, 0);
	for(int i = 0; i < k; ++i){
		scanf("%d", &num_vec[i]);
	}
	int sum, maxsum, start, laststart, end;
	sum = 0;
	start = laststart = end = num_vec[0];
	maxsum = -1;
	bool flag = false;
	for(int i = 0; i < k; ++i){
		sum += num_vec[i];
		if(sum < 0){
			sum = 0;
			if(i+1 < k){
				start = num_vec[i+1];
			}
		}else{
			flag = true;
			if(sum > maxsum){
				maxsum = sum;
				end = num_vec[i];
				laststart = start;
			}
		}
	}
	if(!flag){
		maxsum = 0;
		laststart = num_vec[0];
		end = num_vec[k-1];
	}
	printf("%d %d %d\n", maxsum, laststart, end);
	system("pause");
}