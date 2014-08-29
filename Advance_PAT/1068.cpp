#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> nums(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &nums[i]);
	}
	sort(nums.rbegin(), nums.rend());
	vector<vector<int> > dp;
	vector<vector<bool> > flags;
	for(int i = 0; i <= n; ++i){
		dp.push_back(vector<int>(m+1, 0));
	}
	for(int i = 0; i <= m; ++i){
		flags.push_back(vector<bool>(n+1, false));
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(j < nums[i-1] || dp[i-1][j] > nums[i-1] + dp[i-1][j-nums[i-1]]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = nums[i-1] + dp[i-1][j-nums[i-1]];
				flags[j][i] = true;
			}
		}
	}
	if(dp[n][m] == m){
		bool flag = true;
		for(int i = n; i >= 1; --i){
			if(flags[m][i]){
				if(flag){
					printf("%d", nums[i-1]);
					flag = false;
				}else{
					printf(" %d", nums[i-1]);
				}
				m -= nums[i-1];
			}
		}
		printf("\n");
	}else{
		printf("No Solution\n");
	}
	system("pause");
}