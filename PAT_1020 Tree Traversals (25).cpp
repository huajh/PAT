#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

struct node
{
	node* left;
	node* right;
	int value;
};
int aa[30],bb[30];
int len ;
void building_travel()
{
	int index[30];
	for(int i=0;i<len;i++)
		index[bb[i]] = i;
	node *root = new node;
	root->value = aa[len-1];
	root->right = NULL;
	root->left =NULL;
	for(int i=len-2;i>=0;i--)
	{	
		node* ptr = root,*parent = root;
		int dir = 0;
		while(ptr!=NULL)
		{
			parent = ptr;
			if(index[aa[i]] < index[ptr->value])		
			{
				ptr=ptr->left;
				dir =1;
			}
			else
			{
				ptr = ptr->right;
				dir = 0;
			}
		}
		node* newnode = new node;
		newnode->value = aa[i];
		newnode->right = NULL;
		newnode->left =NULL;
		if(dir == 1) 
			parent->left = newnode;
		else
			parent->right = newnode;
	}
	queue<node*> q;
	q.push(root);
	cout<<root->value;
	bool first = true;
	while(!q.empty())
	{
		node * hh = q.front();
		if(!first) cout<<' '<<hh->value;
		first = false;
		q.pop();
		if(hh->left!=NULL)
			q.push(hh->left);
		if(hh->right!=NULL)
			q.push(hh->right);
	}
	cout<<endl;
}

int main()
{	
	while(cin>>len)
	{
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		for(int i=0;i<len;i++)
			cin>>aa[i];
		for(int i=0;i<len;i++)
			cin>>bb[i];
		building_travel();

	}

}