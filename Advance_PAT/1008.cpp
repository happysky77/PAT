#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int res = 5 * n;
	int last, cur;
	last = cur = 0;
	for(int i = 0; i < n; ++i){
		cin >> cur;
		if(cur > last){
			res += 6 * (cur - last);
		}else{
			res += 4 * (last - cur);
		}
		last = cur;
	}
	cout << res << endl;
	system("pause");
}