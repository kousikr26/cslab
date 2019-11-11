#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct node{
	int val;
	node* left;
	node* right;
};
node* create(int x){
	node* temp =new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->val=x;
}
node* insert(node* root,int val){
	if(root==NULL) return create(val);
	if(val<=root->val) root->left=insert(root->left,val);
	else root->right=insert(root->right,val);
	return root;
}
void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
bool search(node* root,int x){
	if(root==NULL) return false;
	if(root->val==x) return true;
	if(x<root->val) search(root->left,x);
	else search(root->right,x);
}
node* min_node(node* root){
	if(root==NULL) return root;
	while(root->left==NULL) root=root->left;
	return root;
}
node* delete_node(node* root, int x){
	if(root==NULL) return root;
	if(x<root->val) root->left=delete_node(root->left,x);
	else if(x>root->val) root->right=delete_node(root->right,x);
	else{
		if(root->left==NULL){
			node* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			node* temp=root->left;
			delete root;
			return temp;
		}
		else{
			node* temp=min_node(root->right);
			root->val=temp->val;
			delete_node(temp,root->val);
			return root;
		}


	}

}
int main(){
	node* root=create(100);
	insert(root,30);
	insert(root,4);
	insert(root,102);
	insert(root,100);
	insert(root,192);
	insert(root,234);
	inorder(root);
	cout<<endl;
	cout<<search(root,102)<<search(root,234)<<search(root,69);
	cout<<endl;
	delete_node(root,102);
	delete_node(root,234);
	delete_node(root,69);
	cout<<endl;
	inorder(root);
}