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

unordered_map<int,int>m;
void top_view(Node *root,int dist)
{
	if(root==NULL)
		return;
	if(m.find(dist)==m.end())
		m[dist]=root->data;
	top_view(root->left,dist-1);
	top_view(root->right,dist+1);

}

int main()
{
	Node *root=new Node(3);
	root->left=new Node(1);
	root->right=new Node(5);
	root->left->left=new Node(0);
	root->left->right=new Node(2);
	//root->left->right->left=new Node(4);
	//root->left->right->right=new Node(7);
	root->right->right=new Node(6);
	root->right->left=new Node(4);

	cout<<"Top view of this binary search tree is"<<endl;
	top_view(root,0);


	pair<int,int> min=*min_element(m.begin(),m.end());
	pair<int,int> max=*max_element(m.begin(),m.end());

	for(int i=min.first;i<=max.first;i++)
	{
		cout<<m[i]<<" ";
	}
}