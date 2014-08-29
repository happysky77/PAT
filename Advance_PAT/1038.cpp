#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string& s1, const string& s2)
{
	string ss1 = s1 + s2;
	string ss2 = s2 + s1;
	return ss1 < ss2;
}
int main()
{
	int n;
	cin >> n;
	vector<string> str_vec;
	string str;
	for(int i = 0; i < n; ++i){
		cin >> str;
		str_vec.push_back(str);
	}
	sort(str_vec.begin(), str_vec.end(), cmp);
	string res;
	for(auto itr = str_vec.begin(); itr != str_vec.end(); ++itr){
		res += *itr;
	}
	int idx = res.find_first_not_of('0');
	if(idx == -1){
		cout << "0" << endl;
	}else{
		cout << res.substr(idx, res.size()-idx) << endl;
	}
	system("pause");
}