#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode{
	int key;
	Tree left;
	Tree right;
	TreeNode(int v): key(v), left(NULL), right(NULL){}
	TreeNode(): key(0), left(NULL), right(NULL){}
};
Tree build_tree(int *arr, int len)
{
	Tree T = new TreeNode();
	int level = 0;
	int mult = 1;
	while(mult - 1 < len){
		mult *= 2;
		level++;
	}
	// CBT in head
	int full = mult / 2 - 1;
	int remain = len - full;
	int left_leaves = mult / 4;
	int left, right;
	if(remain > left_leaves)
		left = (full - 1) / 2 + left_leaves;
	else
		left = (full - 1) / 2 + remain;
	right = len - 1 - left;
	T->key = arr[left];
	if(left > 0)
		T->left = build_tree(arr, left);
	if(right > 0)
		T->right = build_tree(arr+left+1, right);
	return T;
}
void print_tree(Tree t)
{
	queue<Tree> t_que;
	cout << t->key;
	if(t->left)
		t_que.push(t->left);
	if(t->right)
		t_que.push(t->right);
	while(!t_que.empty()){
		Tree tmp = t_que.front();
		cout << " " << tmp->key;
		if(tmp->left)
			t_que.push(tmp->left);
		if(tmp->right)
			t_que.push(tmp->right);
		t_que.pop();
	}
	cout << endl;
}
int main()
{
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr+n);
	Tree T = build_tree(arr, n);
	print_tree(T);
	system("pause");
}