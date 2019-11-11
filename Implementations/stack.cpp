#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node* prev;
};
class Stack{
	private:
		node* top_node;
	public:
		Stack(){
			node* top_node= new node;
			top_node->prev=NULL;
		}

		
		int pop(){
			node* temp=top_node->prev;
			int popval=top_node->val;
			delete top_node;
			top_node=temp;
			return popval;
		}
		void push(int x){
			node* new_node= new node;
			new_node->val=x;
			new_node->prev=top_node;
			top_node=new_node;
		}
		int top(){
			return top_node->val;
		}

};
int main(){
	Stack mystack;
	mystack.push(3);
	mystack.push(4);
	mystack.push(1);
	cout<<mystack.pop();
	cout<<mystack.top();
	return 0;

}