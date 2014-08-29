#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const int& a, const int& b){
	return a < b;
}
int main(){
	vector<int> int_vec;
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(2);
	sort(int_vec.begin(), int_vec.end(), compare);
	system("pause");
}