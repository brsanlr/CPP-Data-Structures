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


};


int main(){

	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);

	n1->left = n2;
	n1->right = n3;
	n3->right = n4;
	n4->right = n5;

	BinaryTree tree(n1);

	cout << "Depth : " << tree.depth(n1, n1) << endl;
	cout << "Depth : " << tree.depth(n1, n2) << endl;
	cout << "Depth : " << tree.depth(n1, n5) << endl;
	cout << "Depth : " << tree.depth(n3) << endl;



	return 0;
}

