#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
long int maxGreater(long int m, long int n){
	if(m < 0) m = -m;
	if(n < 0) n = -n;
	if(m < n){
		return maxGreater(n, m);
	}
	if(n == 0)
		return m;
	return maxGreater(n, m%n);
}
void getNum(string& str, long int& num, long int& dem){
	bool sign = true;
	if(str[0] == '-'){
		sign = false;
		str = str.substr(1, str.size()-1);
	}
	stringstream ss(str);
	char ch;
	ss >> num >> ch >> dem;
	if(!sign)
		num = -num;
}
int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	long int nume, demo;
	getNum(str, nume, demo);
	long int common;
	common = maxGreater(nume, demo);
	nume /= common;
	demo /= common;
	for(int i = 1; i < n; ++i){
		cin >> str;
		long int tmpNume, tmpDemo;
		getNum(str, tmpNume, tmpDemo);
		common = maxGreater(demo, tmpDemo);
		nume = nume * tmpDemo / common + tmpNume * demo / common;
		demo = demo * tmpDemo / common;
		common = maxGreater(nume, demo);
		nume /= common;
		demo /= common;
	}
	if(nume == 0){
		printf("0\n");
	}else if(nume < 0){
		printf("-");
		nume = -nume;
	}
	if(nume){
		int i = nume/demo;
		int r = nume%demo;
		if(i){
			printf("%d", i);
			if(r){
				printf(" %d/%d", r, demo);
			}
		}else{
			printf("%d/%d", r, demo);
		}
		printf("\n");
	}
	printf("just test\n");
	system("pause");
}