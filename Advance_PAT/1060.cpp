#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void convert(const string& str, string& res, int n, int& exp){
	int len = str.size();
	int i = str.find_first_not_of('0');
	int dot = str.find_first_of('.');
	bool isDot = false;
	if(dot != -1 && i == dot){
		i = str.find_first_not_of('0', dot+1);
		isDot = true;
		exp = dot - i + 1;
	}
	if(i == -1){
		res.assign(n, '0');
		exp = 0;
		return;
	}
	while(i < len){
		if(str[i] != '.'){
			if(res.size() < n)
				res.push_back(str[i]);
			if(!isDot)
				exp++;
		}else{
			isDot = true;
		}
		i++;
	}
	while(res.size() < n){
		res.push_back('0');
	}
}
int main(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	string ares, bres;
	int aexp, bexp;
	aexp = bexp = 0;
	convert(a, ares, n, aexp);
	convert(b, bres, n, bexp);
	int aidx = ares.find_first_not_of('0');
	if(aidx == -1){
		aexp = 0;
	}
	int bidx = bres.find_first_not_of('0');
	if(bidx == -1){
		bexp = 0;
	}
	if(ares == bres && aexp == bexp){
		cout << "YES 0." << ares << "*10^" << aexp << endl;
	}else{
		cout << "NO 0." << ares << "*10^" << aexp << " 0." << bres << "*10^" << bexp << endl;
	}
	system("pause");
}