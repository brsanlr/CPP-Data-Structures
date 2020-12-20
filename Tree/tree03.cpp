#include <iostream>
using namespace std;


// Sadece int veri tipi tutan ve max 2 çocuðu olan bir tasarým.

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data = 0,TreeNode* left = NULL,TreeNode* right = NULL)
	: data(data), left(left), right(right)
	{}
};


// Binary Tree sınıfı

class BinaryTree{
	TreeNode* root;
public:
	BinaryTree(TreeNode* root = NULL) : root(root){}
	bool isEmpty()const{ return root == NULL;}
	TreeNode* getRoot()const{ return root;}
	int height(TreeNode* node){
		if (node){
			int left = height(node->left);
			int right = height(node->right);
			return 1 + max(left,right);
		}
		else {
			return -1;
		}
	}
	// Override : paremetre verilmezse kökün yükselikliği hesapla.
	int height(){
		return height(root);
	}
};


int main(){

	// Bir TreeNode açıp , çocuklarını oluşturuyoruz.

	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(20);
	root->right = new TreeNode(30);
	root->right->right = new TreeNode(40);

	// BinaryTree oluşturuyoruz.Kökü root olacak şekilde..
	BinaryTree tree(root);

	cout << tree.isEmpty() << endl;
	cout << tree.getRoot() << endl;


	cout << tree.height(root) << endl;


	return 0;
}

