#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode{
	int key;
	Tree left;
	Tree right;
	TreeNode(int v): key(v), left(NULL), right(NULL){}
	TreeNode(): key(0), left(NULL), right(NULL){}
};
Tree build_tree( int* arr1, int* arr2, int len )
{
	Tree T = new TreeNode();
	T->key = arr1[len-1];
	int left, right;
	for(int i = 0; i < len; ++i){
		if(arr2[i] == T->key){
			left = i;
			break;
		}
	}
	right = len - 1 - left;
	if(left != 0)
		T->left = build_tree(arr1, arr2, left);
	if(right != 0)
		T->right = build_tree(arr1+left, arr2+left+1, right);
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
	int* a = new int[n];
	int* b = new int[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	Tree t = build_tree(a, b, n);
	print_tree(t);
	system("pause");
}