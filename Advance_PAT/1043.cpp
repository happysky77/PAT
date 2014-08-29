#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int key;
	Node* left;
	Node* right;
	Node(int k): key(k) {left = right = NULL;}
};
Node* buildTree(vector<int>::iterator start, vector<int>::iterator end, bool& buildFlag, bool flag)
{
	if(start == end){
		return NULL;
	}
	Node* node = new Node(*start);
	vector<int>::iterator itr;
	for(itr = start+1; itr != end; ++itr){
		if((flag && *itr >= *start) || (!flag && *itr < *start)){
			break;
		}
	}
	for(vector<int>::iterator it = itr; it != end; ++it){
		if((flag && *it < *start) || (!flag && *it >= *start)){
			buildFlag = false;
			return NULL;
		}
	}
	node->left = buildTree(start+1, itr, buildFlag, flag);
	if(buildFlag){
		node->right = buildTree(itr, end, buildFlag, flag);
	}
	return node;
}
void postOrder(Node* root, vector<int>& post)
{
	if(root->left){
		postOrder(root->left, post);
	}
	if(root->right){
		postOrder(root->right, post);
	}
	post.push_back(root->key);
}
int main()
{
	int n, num;
	cin >> n;
	vector<int> vec;
	for(int i = 0; i < n; ++i){
		cin >> num;
		vec.push_back(num);
	}
	bool flag = true;
	if(vec[vec.size()-1] < vec[0]){
		flag = false;
	}
	bool buildFlag = true;
	Node* root = buildTree(vec.begin(), vec.end(), buildFlag, flag);
	if(buildFlag){
		cout << "YES" << endl;
		vector<int> post;
		postOrder(root, post);
		cout << post[0];
		for(int i = 1; i < n; ++i){
			cout << " " << post[i];
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
	}
	system("pause");
}