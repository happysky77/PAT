#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	//��s�зֳ������Σ�С���κ�ָ����3��string�������
	int exp = 0;
	int idx = s.find_first_of('E');
	for(int i = idx+2; i < s.size(); ++i){
		exp = exp * 10 + s[i] - '0';
	}
	if(s[idx+1] == '-')
		exp *= -1;
	if(s[0] == '-')
		cout << "-";
	if(exp < 0){
		cout << "0.";
		for(int i = 0; i < ((-exp)-1); ++i)
			cout << "0";
		cout << s[1];
		for(int i = 3; i < idx; ++i)
			cout << s[i];
		cout << endl;
	} else if(exp > 0){
		int len = idx - 3;
		//С�����ֳ��� < exp�����������û�С�.��
		if(exp >= len){
			cout << s[1];
			for(int i = 3; i < idx; ++i)
				cout << s[i];
			for(int i = 0; i < (exp - len); ++i)
				cout << "0";
			cout << endl;
		}else{
			cout << s[1];
			for(int i = 0; i < exp; ++i)
				cout << s[3+i];
			cout << ".";
			for(int i = 3+exp; i < idx; ++i)
				cout << s[i];
			cout << endl;
		}
	}else{
		for(int i = 1; i < idx; ++i)
			cout << s[i];
		cout << endl;
	}
	system("pause");
}