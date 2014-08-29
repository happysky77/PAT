#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	string str;
	getline(cin, str);
	string res(str);
	int len = res.size();
	for(int i = 1; i < n; ++i){
		getline(cin, str);
		if(len){
			int minlen = 0;
			while(minlen < res.size() && minlen < str.size() && res[res.size()-1-minlen] == str[str.size()-1-minlen]){
				minlen++;
			}
			if(minlen < len){
				len = minlen;
				res = res.substr(res.size()-len, len);
			}
		}
	}
	if(len == 0){
		cout << "nai" << endl;
	}else{
		cout << res << endl;
	}
	system("pause");
}