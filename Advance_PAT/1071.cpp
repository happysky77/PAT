#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string str, word;
	getline(cin, str);
	vector<string> str_vec;
	bool flag = false;
	for(int i = 0; i < str.size(); ++i){
		if(isalnum(str[i])){
			str[i] = tolower(str[i]);
			word.push_back(str[i]);
			flag = true;
		}else{
			if(flag){
				str_vec.push_back(word);
				flag = false;
				word.clear();
			}
		}
	}
	if(flag){
		str_vec.push_back(word);
	}
	sort(str_vec.begin(), str_vec.end());
	string maxstr;
	int maxlen = 0;
	auto itr = str_vec.begin();
	while(itr != str_vec.end()){
		auto eq = equal_range(itr, str_vec.end(), *itr);
		if(eq.second - eq.first > maxlen){
			maxstr = *itr;
			maxlen = eq.second - eq.first;
		}
		itr = eq.second;
	}
	cout << maxstr << " " << maxlen << endl;
	system("pause");
}