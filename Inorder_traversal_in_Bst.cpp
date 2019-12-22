#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left,*right;

		Node(int data)
		{
			this->data=data;
			left=right=NULL;
		}
};

void inorder(Node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	Node *root=new Node(8);
	root->left=new Node(3);
	root->right=new Node(10);
	root->left->left=new Node(1);
	root->left->right=new Node(6);
	root->left->right->left=new Node(4);
	root->left->right->right=new Node(7);
	root->right->right=new Node(14);
	root->right->right->left=new Node(13);

	cout<<"Inorder traversal of this binary search tree is"<<endl;
	inorder(root);
}