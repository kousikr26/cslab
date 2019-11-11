#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct node{
	int val;
	node* left;
	node* right;
	int height;
};
node* create(int x){
	node* temp =new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->val=x;
	temp->height=1;
}
int get_height(node* root){
	if(root==NULL) return 0;
	return root->height;
}
node *rr(node *y)  
{  
	node *x = y->left;  
	node *T2 = x->right;  

	x->right = y;  
	y->left = T2;  
	y->height = max(get_height(y->left),get_height(y->right)) + 1;
	x->height = max(get_height(x->left),get_height(x->right)) + 1;

	return x;  
}  

node *lr(node *x)  
{  
	node *y = x->right;  
	node *T2 = y->left;  
  
 
	y->left = x;  
	x->right = T2;  

	x->height = max(get_height(x->left), get_height(x->right)) + 1;
	y->height = max(get_height(y->left), get_height(y->right)) + 1;
 
	return y;  
}  
node* insert(node* root,int val){
	if(root==NULL) return create(val);
	if(val<=root->val) root->left=insert(root->left,val);
	else root->right=insert(root->right,val);
	root->height=1+max(get_height(root->left),get_height(root->right));
	if(get_height(root->left)-get_height(root->right)>1 && val<root->left->val) return rr(root);
	if(get_height(root->left)-get_height(root->right)>1 && val>root->left->val){root->left=lr(root->left); return rr(root);}
	if(get_height(root->left)-get_height(root->right)<-1 && val>root->right->val) return lr(root);
	if(get_height(root->left)-get_height(root->right)<-1 && val<root->right->val){root->right=rr(root->right); return lr(root);}
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
		if(root==NULL) return root;
		root->height=1+max(get_height(root->left),get_height(root->right));
		int balance=get_height(root->left)-get_height(root->right);
		if(balance>1 && get_height(root->left->left)-get_height(root->left->right)>=0) return rr(root);
		if(balance>1 && get_height(root->left->left)-get_height(root->left->right)<0){
			root->left=lr(root->left);
			return rr(root);
		}
		if(balance<-1 && get_height(root->right->left)-get_height(root->right->right)<=0) return lr(root);
		if(balance<-1 && get_height(root->right->left)-get_height(root->right->right)>0){
			root->right=rr(root->right);
			return lr(root);
		}
		return root;
	}

}
int main(){
	node* root=NULL;
	root = insert(root, 9);  
	root = insert(root, 5);  
	root = insert(root, 10);  
	root = insert(root, 0);  
	root = insert(root, 6);  
	root = insert(root, 11);  
	root = insert(root, -1);  
	root = insert(root, 1);  
	root = insert(root, 2);
	inorder(root);
	cout<<endl;
	cout<<search(root,102)<<search(root,234)<<search(root,69);
	cout<<endl;
	//cout<<delete_node(root,102)<<delete_node(root,234)<<delete_node(root,69);
	cout<<endl;
	inorder(root);
}