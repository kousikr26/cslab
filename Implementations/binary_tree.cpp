#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node* left;
	node* right;
};


void level_traverse(node* traverse,int level){
	if(traverse==NULL) return;
	if(level==1) cout<<traverse->val<<" ";
	else{
		level_traverse(traverse->left,level-1);
		level_traverse(traverse->right,level-1);
	}
}


void levelorder(node* root,int height){
	
	for(int i=1;i<=height;i++){
		
		node* traverse=root;
		level_traverse(traverse,i);
		cout<<endl;
	}

}

node* insrec(node* root,int level,int x){

	if(root->left==NULL){
		node* temp=new node;
		temp->val=x;
		temp->left=NULL;
		temp->right=NULL;
		root->left=temp;
		cout<<"soop"<<endl;
		return root;
	}
	if(root->right==NULL){
		node* temp=new node;
		temp->val=x;
		temp->right=NULL;
		temp->right=NULL;
		root->right=temp;
		return root;
	}
	if(root==NULL) return root;
	if(level==1) cout<<root->val<<" ";
	else{
		root=insrec(root->left,level-1,x);
		root=insrec(root->right,level-1,x);
	}
}
void insert(node* root,int x,int height){
	
	if(root->left==NULL && root->right==NULL && root->val==-1) {root->val=x;return;}
	root=insrec(root,height,x);
}



int main(){
	node* root= new node;
	root->left=NULL;
	root->right=NULL;
	root->val=-1;
	int height=1;
	levelorder(root,height);
	cout<<endl;
	insert(root,3,height);
	insert(root,4,height+1);
	insert(root,5,height+1);
	insert(root,6,height+2);
	insert(root,7,height+2);
	insert(root,8,height+2);
	levelorder(root,height+2);
	return 0;

}