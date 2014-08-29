#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int n1, n2, start;
	if(n%2 == 0)
		start = 4;
	else
		start = 3;
	for(int i = start; i <= n; i+=2){
		n1 = (n + 2 - i) / 2;
		if(n1 <= i){
			n2 = i;
			break;
		}
	}
	for(int i = 0; i < (n1-1); ++i){
		cout << s[i];
		for(int j = 0; j < (n2-2); ++j)
			cout << ' ';
		cout << s[n-1-i] << endl;
	}
	for(int i = 0; i < n2; ++i)
		cout << s[n1-1+i];
	cout << endl;
	system("pause");
}