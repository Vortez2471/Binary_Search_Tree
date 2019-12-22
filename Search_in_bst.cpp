#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
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

void search(Node *root,int key,bool & flag)
{
	if(root==NULL)
		return;
	if(root->data==key)
	{
		flag=1;
	}
	else if(root->data>key)
		search(root->left,key,flag);
	else
		search(root->right,key,flag);
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

	int k;
	bool flag=0;
	cout<<"Enter key to find"<<endl;
	cin>>k;

	search(root,k,flag);
	if(flag)
		cout<<"Key Found"<<endl;
	else
		cout<<"Not Found"<<endl;
}