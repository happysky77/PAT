#include <iostream>
#include <string>
using namespace std;
bool check_account(string& str)
{
	bool flag = false;
	for(int i = 0; i < str.size(); ++i){
		if(str[i] == '1' || str[i] == '0' || str[i] == 'l' || str[i] == 'O'){
			flag = true;
			if(str[i] == '1')
				str[i] = '@';
			else if(str[i] == '0')
				str[i] = '%';
			else if(str[i] == 'l')
				str[i] = 'L';
			else if(str[i] == 'O')
				str[i] = 'o';
		}
	}
	return flag;
}
int main()
{
	int n;
	cin >> n;
	int count = 0;
	string user[1005];
	string passwd[1005];
	int idx[1005];
	for(int i = 0; i < n; ++i)
		idx[i] = 0;
	for(int i = 0; i < n; ++i){
		cin >> user[i] >> passwd[i];
		if(check_account(passwd[i])){
			count++;
			idx[i] = 1;
		}
	}
	if(count){
		cout << count << "\n";
		for(int i = 0; i < n; ++i){
			if(idx[i])
				cout << user[i] << " " << passwd[i] << "\n";
		}
	}else{
		if(n == 1)
			cout << "There is 1 account and no account is modified\n";
		else
			cout << "There are " << n << " accounts and no account is modified\n";
	}
	system("pause");
}