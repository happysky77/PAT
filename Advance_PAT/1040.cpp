#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int dp[1002][1002];
int max3(int x, int y, int z)
{
	int a = max(x, y);
	return max(a, z);
}
int sym(string& s, int start, int end)
{
	if(start == end) return 1;
	if(start > end) return 0;
	if(dp[start][end] != -1)
		return dp[start][end];
	if(s[start] == s[end]){
		//������s[start] == s[end]����һ������dp[start+1][end-1] + 2, ��Ϊ����start+1��end-1���ǶԳƵ�
		dp[start+1][end-1] = sym(s, start+1, end-1);
		dp[start+1][end] = sym(s, start+1, end);
		dp[start][end-1] = sym(s, start, end-1);
		if(dp[start+1][end-1] == end-start-1)
			return dp[start][end] = 2 + dp[start+1][end-1];
		else
			return dp[start][end] = max3(dp[start+1][end-1], dp[start+1][end], dp[start][end-1]);
	} else {
		return max(dp[start][end-1] = sym(s, start, end-1), dp[start+1][end] = sym(s, start+1, end));
	}
	return -1;
}
int main()
{
	string s;
	getline(cin, s);
	for(int i = 0; i < 1002; ++i){
		for(int j = 0; j < 1002; ++j)
			dp[i][j] = -1;
	}
	int len = sym(s, 0, s.length()-1);
	cout << len << endl;
	system("pause");
}