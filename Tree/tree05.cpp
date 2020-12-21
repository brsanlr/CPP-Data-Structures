#include <iostream>
using namespace std;


// Sadece int veri tipi tutan ve max 2 çocugu olan bir tasarım.

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data = 0,TreeNode* left = NULL,TreeNode* right = NULL)
	: data(data), left(left), right(right)
	{}
};


// Binary Search Tree sınıfı

class BinarySearchTree{
	TreeNode* root;
public:
	BinarySearchTree(TreeNode* root = NULL) : root(root){}
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

	int depth(TreeNode* start,TreeNode* finish){
		if (start){
			if (start == finish){
				return 0;
			}
			int left = depth(start->left,finish);
			int right = depth(start->right,finish);
			return 1 + max(left,right);
		}
		else {
			return INT_MIN;
		}
	}
	int depth(TreeNode* finish){
		return depth(root,finish);
	}

	// EKLEME FONKSİYONU

	TreeNode* insert(TreeNode* start,int data){
		if (start){
			if (data < start->data){
				start->left = insert(start->left,data);
			}
			else {
				start->right = insert(start->right,data);
			}
		}
		else {
			return new TreeNode(data);
		}
		return start;
	}

	void insert(int data){
		root = insert(root,data);
	}

};


int main(){

	BinarySearchTree bst;
	cout << bst.isEmpty() << endl;

	bst.insert(10);

	cout << bst.isEmpty() << endl;



	return 0;
}

