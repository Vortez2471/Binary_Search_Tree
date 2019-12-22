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

void insert(Node* & root,int key)
{
	if(root==NULL)
	{
		root=new Node(key);
		return;
	}
	else if(root->data<key)
		insert(root->right,key);
	else
		insert(root->left,key);
}

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
	cout<<"Enter the number of entries"<<endl;
	int n,k;
	cin>>n;
	Node *root=NULL;

	for(int i=0;i<n;i++)
	{
		cin>>k;
		insert(root,k);
	}

	cout<<"Inorder traversal of this binary search tree is"<<endl;
	inorder(root);
}