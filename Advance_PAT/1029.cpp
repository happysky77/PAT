#include <iostream>
#include <vector>
using namespace std;
int main(){
	long int n, m, num;
	scanf("%ld", &n);
	vector<long int> num1_vec(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%ld", &num1_vec[i]);
	}
	scanf("%ld", &m);
	vector<long int> num2_vec(m, 0);
	for(int i = 0; i < m; ++i){
		scanf("%ld", &num2_vec[i]);
	}
	int k = (n + m - 1)/2;
	int aidx, bidx;
	aidx = bidx = 0;
	int idx = -1;
	int res = 0;
	for(idx = -1; aidx < n && bidx < m;){
		if(num1_vec[aidx] <= num2_vec[bidx]){
			res = num1_vec[aidx];
			idx++;
			aidx++;
		}else{
			res = num2_vec[bidx];
			idx++;
			bidx++;
		}
		if(idx == k){
			printf("%d\n", res);
			break;
		}
	}
	if(idx < k && aidx < n){
		printf("%d\n", num1_vec[aidx+k-idx-1]);
	}
	if(idx < k && bidx < m){
		printf("%d\n", num2_vec[bidx+k-idx-1]);
	}
	system("pause");
}