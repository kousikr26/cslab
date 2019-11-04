#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
#define mod 1000000007
const int INF = 1e9;
#define fori(n) for(lli i=0;i<n;i++)
struct node{
	int key,priority;
	node* left;
	node* right;
};
node* createNode(int key){
	node* temp= new node;
	temp->key=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->priority=rand()%1000;

}
node* search(node* root,int key){
	if(root==NULL || root->key==key) return root;
	else if(key<=root->key) return search(root->left,key);
	else return search(root->right,key);
}
node* leftRot(node* pivot){
	
	node* rightChild=pivot->right;
	node* temp=rightChild->left;
	rightChild->left=pivot;
	pivot->right=temp;
	return rightChild;
}
node* rightRot(node* pivot){
	
	node* leftChild=pivot->left;
	node* temp=leftChild->right;
	leftChild->right=pivot;
	pivot->left=temp;
	return leftChild;
}

node* insert(node* root,int key){
	if(root==NULL) return createNode(key);
	if(key<=root->key){
		root->left=insert(root->left,key);
		if(root->priority<root->left->priority){
			root=rightRot(root);
		}

	}
	else{
		root->right=insert(root->right,key);
		if(root->priority<root->right->priority){
			root=leftRot(root);
		}
	}
	return root;

}
node* del(node* root,int key){
	if(root==NULL) return root;
	if(key<root->key){
		root->left=del(root->left,key);

	}
	else if(key>root->key){
		root->right=del(root->right,key);
	}
	else if(root->left==NULL){
		node *temp=root->right;

		root=temp;
	}
	else if(root->right==NULL){
		node *temp=root->left;
		
		root=temp;
	}

	else if(root->right->priority>root->left->priority){
		root=leftRot(root);
		root->left=del(root->left,key);

	}
	else{
		root=rightRot(root);
		root->right=del(root->right,key);

	}

	return root;

}
int main(){

	return 0;
}