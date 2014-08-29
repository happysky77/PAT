#include <iostream>
using namespace std;
char transfer(int i)
{
	if(i < 10)
		return i + '0';
	else
		return i - 10 + 'A';
}
int main()
{
	int color[3];
	cin >> color[0] >> color[1] >> color[2];
	cout << "#";
	for(int i = 0; i < 3; i++){
		cout << transfer(color[i] / 13);
		cout << transfer(color[i] % 13);
	}
	cout << endl;
	system("pause");
}