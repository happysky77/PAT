#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num)
{
	if(num < 2){
		return false;
	}else{
		bool flag = true;
		for(int i = 2; i <= (int)sqrt((double)num); ++i){
			if(num%i == 0){
				flag = false;
				break;
			}
		}
		return flag;
	}
}
int reverseNum(int n, int d)
{
	int sum = 0;
	do{
		sum = sum * d + n % d;
		n /= d;
	}while(n);
	return sum;
}
int main(){
	int n, d;
	while(scanf("%d", &n) != EOF && n >= 0){
		scanf("%d", &d);
		if(isPrime(n) && isPrime(reverseNum(n, d))){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	system("pause");
}