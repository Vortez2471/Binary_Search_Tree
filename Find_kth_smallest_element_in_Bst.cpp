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

void inorder(Node *root,int & k)
{
	if(root==NULL)
		return;
	inorder(root->left,k);
	k--;
	if(k==0)
		cout<<"Kth smallest element is "<<root->data<<endl;
	inorder(root->right,k);
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

	for(int i=0;i<7;i++)
	{
		cout<<"Enter k"<<endl;
		cin>>k;
		inorder(root,k);
	}
}