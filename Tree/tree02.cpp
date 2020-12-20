#include <iostream>
using namespace std;


// Sadece int veri tipi tutan ve max 2 çocugu olan bir tasarim.

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
	BinaryTree() : root(NULL){}
	bool isEmpty()const{ return root == NULL;}
	TreeNode* getRoot()const{ return root;}
};


int main(){

	// İçi boş ve kökü NULL
	BinaryTree btree;

	cout << btree.isEmpty() << endl;
	cout << btree.getRoot() << endl;


	return 0;
}
