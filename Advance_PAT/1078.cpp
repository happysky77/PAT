#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int num){
	if(num < 2){
		 return false;
	}else{
		for(int i = 2; i <= (int)sqrt((double)num); ++i){
			if(num%i == 0){
				return false;
			}
		}
		return true;
	}
}
int minPrime(int num){
	while(!isPrime(num)){
		num++;
	}
	return num;
}
int main(){
	int m, n, num;
	scanf("%d%d", &m, &n);
	m = minPrime(m);
	vector<bool> isVisited(m ,false);
	while(n--){
		scanf("%d", &num);
		int pos = num%m;;
		bool isFound = true;
		if(!isVisited[pos]){
			isVisited[pos] = true;
		}else{
			int i = 1;
			for(i = 1; i < m; ++i){
				if(!isVisited[(pos+i*i)%m]){
					pos = (pos + i*i)%m;
					isVisited[pos] = true;
					break;
				}
			}
			if(i == m){
				isFound = false;
			}
		}
		if(isFound){
			printf("%d", pos);
		}else{
			printf("-");
		}
		if(n){
			printf(" ");
		}
	}
	printf("\n");
	system("pause");
}