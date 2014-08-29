#include <iostream>
#include <stack>
using namespace std;
void check_stack(int* arr, int len, int cap)
{
	bool flag = true;
	stack<int> s;
	int start = 1;
	for(int i = 0; i < len; ++i){
		if(flag){
			if(s.empty() || s.top() != arr[i]){
				while(start <= arr[i]){
					s.push(start);
					if(s.size() > cap){
						flag = false;
						break;
					}
					start++;
				}
			}
			if(flag && s.size()>=1 && s.top() == arr[i])
				s.pop();
			else{
				flag = false;
				break;
			}
		}
	}
	if(flag)
		cout << "YES" <<endl;
	else
		cout << "NO" << endl;
}
int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	int* arr = new int[n];
	for(int i = 0; i < k; ++i){
		for(int j = 0; j < n; ++j){
			cin >> arr[j];
		}
		check_stack(arr, n, m);
	}
	delete []arr;
	system("pause");
}