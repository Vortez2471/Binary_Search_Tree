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

void levelorder_queue(Node *root)
{
	if(root==NULL)
		return;
	queue<Node*>q;
	Node *temp=root;
	q.push(root);

	while(!q.empty())
	{
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);

		temp=q.front();
	}
}

int height(Node*root)
{
	if(root==NULL)
		return 0;

	int h1=height(root->left)+1;
	int h2=height(root->right)+1;

	return max(h1,h2);
}

void levelorder(Node *root,int height)
{
	if(root==NULL)
		return;
	if(height==1)
		cout<<root->data<<" ";
	else if(height>1)
	{
		levelorder(root->left,height-1);
		levelorder(root->right,height-1);
	}
}

void print_levelorder(Node *root)
{
	int h=height(root);

	for(int i=1;i<=h;i++)
		levelorder(root,i);
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

	cout<<"Levelorder traversal of this binary search tree by queue method is"<<endl;
	levelorder_queue(root);
	cout<<endl;

	cout<<"Levelorder traversal of this binary search tree by simple method is"<<endl;
	print_levelorder(root);

}