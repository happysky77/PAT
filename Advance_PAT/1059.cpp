#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int num){
	bool flag = true;
	for(int i = 2; i <= (int)sqrt(double(num)); ++i){
		if(num%i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
	long n;
	cin >> n;
	vector<int> primes;
	primes.push_back(2);
	for(int i = 3; i < 100000; ++i){
		if(isPrime(i)){
			primes.push_back(i);
			if(primes.size() == 1000){
				break;
			}
		}
	}
	cout << n << "=";
	if(n == 1){
		cout << n << endl;
	}else{
		bool flag = false;
		for(int i = 0; i < primes.size(); ++i){
			if(n % primes[i] == 0){
				int count = 0;
				while(n % primes[i] == 0){
					count++;
					n /= primes[i];
				}
				if(flag){
					cout << "*";
				}
				flag = true;
				cout << primes[i];
				if(count > 1){
					cout << "^" << count;
				}
			}
		}
		cout << endl;
	}
	system("pause");
}