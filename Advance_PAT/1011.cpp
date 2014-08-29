#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double arr[3][3];
	int maxidx[3] = {0};
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> arr[i][j];
			if(arr[i][j] > arr[i][maxidx[i]]){
				maxidx[i] = j;
			}
		}
	}
	double profit = 1.0;
	for(int i = 0; i < 3; ++i){
		if(maxidx[i] == 0){
			cout << "W ";
		}else if(maxidx[i] == 1){
			cout << "T ";
		}else{
			cout << "L ";
		}
		profit *= arr[i][maxidx[i]];
	}
	profit = (profit * 0.65 - 1.0) * 2.0;
	cout << fixed << setprecision(2) << profit << endl;
	system("pause");
}