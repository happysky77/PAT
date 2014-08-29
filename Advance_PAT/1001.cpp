#include <iostream>
#include <stack>
using namespace std;
void printNum(int num)
{
	if(num < 1000){
		cout << num << endl;
	}else{
		stack<int> num_stack;
		while(num){
			num_stack.push(num % 1000);
			num /= 1000;
		}
		printf("%d", num_stack.top());
		num_stack.pop();
		while(!num_stack.empty()){
			printf(",%03d", num_stack.top());
			num_stack.pop();
		}
		cout << endl;
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	int res = a + b;
	if(res < 0)
		cout << "-";
	if(res < 0){
		res = -res;
	}
	printNum(res);
	system("pause");
}