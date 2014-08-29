#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	set<char> char_set;
	for(int i = 0; i < s2.length(); ++i){
		char_set.insert(s2[i]);
	}
	for(int i = 0; i < s1.size(); ++i){
		set<char>::iterator itr = char_set.find(s1[i]);
		if(itr == char_set.end())
			cout << s1[i];
	}
	cout << endl;
	system("pause");
}