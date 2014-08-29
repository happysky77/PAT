#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> num(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}
	sort(num.begin(), num.end());
	if(n == 1){
		printf("No Solution\n");
	}else{
		int left = 0;
		int right = n-1;
		bool flag = false;
		while(left < right && left < n && right >= 0){
			int sum = num[left] + num[right];
			if(sum == m){
				printf("%d %d\n", num[left], num[right]);
				flag = true;
				break;
			}else if(sum > m){
				right--;
			}else{
				left++;
			}
		}
		if(!flag){
			printf("No Solution\n");
		}
	}
	system("pause");
}