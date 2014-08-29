#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string digits[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const string units[4] = {"Wan", "Shi", "Bai", "Qian"};
int main()
{
	int num;
	scanf("%d", &num);
	if(num < 0){
		cout << "Fu ";
		num = -num;
	}
	if(num == 0){
		cout << "ling" << endl;
	}else{
		vector<int> digit_vec;
		while(num){
			digit_vec.push_back(num%10);
			num/=10;
		}
		bool isZero = false;
		int first = 0;
		while(digit_vec[first] == 0){
			first++;
		}
		for(int i = digit_vec.size()-1; i > first; --i){
			if(digit_vec[i]){
				if(isZero && i != 3){
					cout << "ling ";
				}
				cout << digits[digit_vec[i]] << " ";
				isZero = false;
			}else{
				isZero = true;
			}

			if(i == 8){
				cout << "Yi ";
			}else if(i == 4){
				cout << "Wan ";
			}else{
				if(!isZero){
					cout << units[i%4] << " ";
				}
			}
		}
		if(digit_vec[first]){
			if(isZero){
				cout << "ling ";
			}
			cout << digits[digit_vec[first]];
			if(first == 8){
				cout << " Yi";
			}else if(first){
				cout << " " << units[first%4];
				if(first > 4){
					cout << " Wan";
				}
			}
			cout << endl;
		}
	}
	system("pause");
}