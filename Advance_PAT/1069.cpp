#include <iostream>
#include <algorithm>
using namespace std;
void resort ( int n, int& a, int& b, int* arr)
{
	for(int i = 0; i < 4; ++i)
		arr[i] = 0;
	int idx = 0;
	while(n){
		arr[idx++] = n%10;
		n /= 10;
	}
	sort(arr, arr+4);
	a = b = 0;
	for(int i = 0; i < 4; ++i){
		b = b * 10 + arr[i];
		a = a * 10 + arr[3-i];
	}
}
void printArr(int* arr, bool flag)
{
	// non-increasing
	if(flag){
		for(int i = 3; i >=0; --i)
			cout << arr[i];
	} else {
		for(int i = 0; i < 4; ++i)
			cout << arr[i];
	}
}
void printDiff(int diff)
{
	int arr[4];
	for(int i = 0; i < 4; ++i)
		arr[i] = 0;
	int idx = 0;
	while(diff){
		arr[idx++] = diff%10;
		diff /= 10;
	}
	for(int i = 3; i >=0 ;--i)
		cout << arr[i];
	cout << "\n";
}
int main()
{
	int n;
	cin >> n;
	int a, b, diff;
	a = b = diff = 0;
	int arr[4];
	resort( n, a, b, arr);
	diff = a - b;
	if(diff == 0) {
		printArr(arr, true);
		cout << " - ";
		printArr(arr, false);
		cout << " = 0000\n";
	} else {
		while(diff != 6174){
			printArr(arr, true);
			cout << " - ";
			printArr(arr, false);
			cout << " = ";
			printDiff(diff);
			resort( diff, a, b, arr);
			diff = a - b;
		}
		printArr(arr, true);
		cout << " - ";
		printArr(arr, false);
		cout << " = 6174\n";
	}
	system("pause");
}