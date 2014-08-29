#include <iostream>
#include <algorithm>
using namespace std;
typedef struct AVLNode* AVLTree;
struct AVLNode{
	int elem;
	AVLTree left;
	AVLTree right;
	int height;
	AVLNode(): elem(0), height(0), left(NULL), right(NULL) {};
};
int height(AVLTree tree)
{
	if(tree == NULL)
		return -1;
	else
		return tree->height;
}
AVLTree singleRotateLeft(AVLTree k2)
{
	AVLTree k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}
AVLTree singleRotateRight(AVLTree k2)
{
	AVLTree k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(k2->height, height(k1->right)) + 1;
	return k1;
}
AVLTree doubleRotateLeft(AVLTree k3)
{
	k3->left = singleRotateRight(k3->left);
	return singleRotateLeft(k3);
}
AVLTree doubleRotateRight(AVLTree k3)
{
	k3->right = singleRotateLeft(k3->right);
	return singleRotateRight(k3);
}
AVLTree insert(int elem, AVLTree tree)
{
	if(tree == NULL){
		tree = new AVLNode();
		tree->elem = elem;
		tree->height = 0;
		tree->left = NULL;
		tree->right = NULL;
	}else{
		if(elem < tree->elem){
			tree->left = insert(elem, tree->left);
			if(height(tree->left) - height(tree->right) == 2){
				if(elem < tree->left->elem )
					tree = singleRotateLeft(tree);
				else
					tree = doubleRotateLeft(tree);
			}
		} else if (elem > tree->elem){
			tree->right = insert(elem, tree->right);
			if(height(tree->right) - height(tree->left) == 2){
				if(elem > tree->right->elem )
					tree = singleRotateRight(tree);
				else
					tree = doubleRotateRight(tree);
			}
		}
	}
	tree->height = max(height(tree->left), height(tree->right)) + 1;
	return tree;
}
int main()
{
	int n;
	cin >> n;
	AVLTree tree = NULL;
	int num;
	for(int i = 0; i < n; ++i){
		cin >> num;
		tree = insert(num, tree);
	}
	cout << tree->elem << endl;
	system("pause");
}