#include <iostream>
#include <vector>
using namespace std;
void check_palind(long num, long base)
{
	vector<long> arr;
	//注意num < 10的情形（包含了num==0的情形）
	if(num < 10){
		cout << "Yes" << endl;
		cout << num << endl;
	}else{
		while(num){
			arr.push_back(num % base);
			num /= base;
		}
		bool flag = true;
		int len = arr.size();
		for(int i = 0; i < len/2; ++i){
			if(arr[i] != arr[len-i-1]){
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		for(int i = len-1; i > 0; --i)
			cout << arr[i] << " ";
		cout << arr[0] << endl;
	}
}
int main()
{
	long num, base;
	cin >> num >> base;
	check_palind(num, base);
	system("pause");
}