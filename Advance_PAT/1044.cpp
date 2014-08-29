#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> nums(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &nums[i]);
	}
	bool isFind = false;
	int sum = 0;
	int start = 0;
	int mindiff = INT_MAX;
	vector<pair<int, int> > res;
	for(int i = 0; i < n; ++i){
		sum += nums[i];
		if(sum == m){
			isFind = true;
			printf("%d-%d\n", start+1, i+1);
			sum -= nums[start];
			start++;
		}else if(sum > m){
			if(!isFind){
				if(sum - m < mindiff){
					mindiff = sum - m;
					res.clear();
					res.push_back(pair<int, int>(start, i));
				}else if(sum - m == mindiff){
					res.push_back(pair<int, int>(start, i));
				}
			}
			while(sum-nums[start] > m){
				sum -= nums[start];
				start++;
				if(!isFind){
					if(sum - m < mindiff){
						mindiff = sum - m;
						res.clear();
						res.push_back(pair<int, int>(start, i));
					}else if(sum - m == mindiff){
						res.push_back(pair<int, int>(start, i));
					}
				}
			}
			sum -= nums[start];
			start++;
			if(sum == m){
				isFind = true;
				printf("%d-%d\n", start+1, i+1);
				sum -= nums[start];
				start++;
			}
		}
	}
	if(!isFind){
		for(auto itr = res.begin(); itr != res.end(); ++itr){
			printf("%d-%d\n", itr->first+1,  itr->second+1);
		}
	}
	system("pause");
}