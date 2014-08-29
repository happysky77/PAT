#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str, newstr;
	cin >> str;
	int c = 0;
	for(int i = str.size()-1; i >= 0; --i){
		int tmp = str[i] - '0';
		tmp = tmp * 2 + c;
		newstr.push_back('0' + tmp%10);
		c = tmp/10;
	}
	if(c){
		newstr.push_back('0' + c);
	}
	set<char> str_set(str.begin(), str.end());
	set<char> newstr_set(newstr.begin(), newstr.end());
	if(str_set.size() == newstr_set.size()){
		bool flag = true;
		for(auto itr = str_set.begin(); itr != str_set.end(); ++itr){
			if(newstr_set.find(*itr) == newstr_set.end()){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}else{
		cout << "No" << endl;
	}
	reverse(newstr.begin(), newstr.end());
	cout << newstr << endl;
	system("pause");
}