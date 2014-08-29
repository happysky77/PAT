#include <iostream>
using namespace std;
long ones[10][10];
int main()
{
	long num;
	cin >> num;
	for(int i = 0; i < 10; ++i)
		ones[0][i] = 1;
	long mult = 1;
	for(int i = 1; i < 10; ++i){
		mult *= 10;
		ones[i][0] = ones[i-1][0] * 10 + mult;
		for(int j = 1; j < 10; ++j)
			ones[i][j] = ones[i][0];
	}
	mult = 1;
	for(int i = 0; i < 10; ++i){
		mult *= 10;
		ones[i][1] += mult - 1;
	}
	if(num < 10)
		cout << 1 << endl;
	else{
		int sum = 0;
		if( num % 10 )
			sum = 1;
		int old = num;
		num /= 10;
		int idx = 0;
		int div = 10;
		while(num){
			int a = num % 10;
			for(int i = 0; i < a; ++i)
				sum += ones[idx][i];
			if(a > 1) sum += 1;
			else if(a == 1) sum += old % div + 1; 
			num /= 10;
			div *= 10;
			idx++;
		}
		cout << sum << endl;
	}
	system("pause");
}