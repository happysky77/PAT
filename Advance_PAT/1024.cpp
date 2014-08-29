#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalind(string str){
	int left = 0;
	int right = str.size() - 1;
	bool flag = true;
	while(left < right){
		if(str[left++] != str[right--]){
			flag = false;
			break;
		}
	}
	return flag;
}
string reverseSum(string num){
	string sum;
	int c = 0;
	int size = num.size() - 1;
	for(int i = 0; i <= size; ++i){
		int tmp = num[i] - '0' + num[size-i] - '0' + c;
		sum.push_back('0' + tmp%10);
		c = tmp / 10;
	}
	if(c){
		sum.push_back('0' + c);
	}
	reverse(sum.begin(), sum.end());
	return sum;
}
int main()
{
	string num;
	int k;
	cin >> num >> k;
	int step = 0;
	while(!isPalind(num) && step < k){
		num = reverseSum(num);
		step++;
	}
	cout << num << endl;
	cout << step << endl;
	system("pause");
}