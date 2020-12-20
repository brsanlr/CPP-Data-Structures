#include <iostream>
using namespace std;


// Sadece int veri tipi tutan ve max 2 �ocu�u olan bir tasar�m.

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data = 0,TreeNode* left = NULL,TreeNode* right = NULL)
	: data(data), left(left), right(right)
	{}
};


int main(){

	TreeNode* root = NULL;

	// K�k� olu�turma.
	root = new TreeNode(10);
	// Sol �ocuk
	root->left = new TreeNode(20);
	// Sa� �ocuk
	root->right = new TreeNode(30);


	cout <<"Root : "<<root->data << endl;
	cout <<"Left Child : "<<root->left->data << endl;
	cout <<"Right Child : "<<root->right->data << endl;

	return 0;
}
