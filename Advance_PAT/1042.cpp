#include <iostream>
using namespace std;
void shuffle(int src[54], int dest[54], int order[54])
{
	for(int i = 0; i < 54; ++i){
		dest[order[i]-1] = src[i];
	}
	for(int i = 0; i < 54; ++i){
		src[i] = dest[i];
	}
}
void printChar(int n)
{
	int tmp = n / 13;
	if(tmp == 0){
		cout << "S";
	}else if(tmp == 1){
		cout << "H";
	}else if(tmp == 2){
		cout << "C";
	}else if(tmp == 3){
		cout << "D";
	}else if(tmp == 4){
		cout << "J";
	}
	cout << n % 13 + 1;
}
void printResult(int dest[54])
{
	printChar(dest[0]);
	for(int i = 1; i < 54; ++i){
		cout << " ";
		printChar(dest[i]);
	}
	cout << endl;
}
int main()
{
	int repeat;
	int order[54];
	cin >> repeat;
	for(int i = 0; i < 54; i++)
		cin >> order[i];
	int src[54];
	for(int i = 0; i < 54; i++)
		src[i] = i;
	int dest[54];
	for(int r = 0; r < repeat; r++){
		shuffle(src, dest, order);
	}
	printResult(dest);
	system("pause");
}