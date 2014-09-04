#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        getAns(n, 0, 0, "", ans);
        return ans;
    }

private:
    void getAns(int n, int pos, int neg, string temp, vector<string> &ans) {
        if (pos < neg) {
            return;
        }
        if (pos + neg == 2 * n) {
            if (pos == neg) {
                ans.push_back(temp);
            }
            return;
        }
        getAns(n, pos + 1, neg, temp + '(', ans);
        getAns(n, pos, neg + 1, temp + ')', ans);
    }
};
int main(){
	Solution test;
	vector<string> res = test.generateParenthesis(6);
	cout << res.size() << endl;
	system("pause");
}