#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
#define mod 1000000007
const int INF = 1e9;
#define fori(n) for(lli i=0;i<n;i++)

struct node{
	int value;
	node* next;
};

node* createNode(int val){
	node* temp =new node;
	node->value=val;
	node->next=NULL;
	return temp;

}
node* append(node* head,int val){
	if(head==NULL){
		head=createNode(val)
		return head;
	}
	else{
		node* traverse=head;
		while(traverse->next!=NULL){
			traverse=head->next;
		}
		node* temp=createNode(val);
		traverse->next=temp;
		return head;
	}

}
bool search(node* head,int val){
	if(head==NULL){
		return false;
	}
	else{
		node* traverse=head;
		while(traverse->next!=NULL){
			traverse=head->next;
			if(traverse->value==val) return true;

		}
		return false;

	}

}
bool deleteNode(node* head,int val){
	if(head==NULL){
		return false;
	}
	else if(head->value==val) return NULL;
	else{
		node* prev=head;
		node* traverse=head->next;
		bool found=false;
		while(traverse->next!=NULL){
			if(traverse->value==val){
				found=true;
				break
			}

		}
		if(!found) return false;
		prev->next=traverse->next;
		delete(traverse);

	}

}

int main(){
	return 0;

}