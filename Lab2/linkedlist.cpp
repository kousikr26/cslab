#include <iostream>
#include <cmath>
using namespace std;

struct node{
	int x;
	int y;
	struct node* next;
};
node* addFirst(int xnew,int ynew);
void printLinkedList();
node* delFirst();
int Del(int xdel,int ydel);
bool Search(int xsearch,int ysearch);
int Length();
int Search(double d);

struct node* first=NULL;

int main(){
	unsigned long long int testcases;
	
	int func,a,b;
	double d;
	cin>>testcases;
	for(int i=0;i<testcases;i++){
		cin>>func;
		if(func==1){
			cin>>a;
			cin>>b;
			addFirst(a,b);
		}
		else if(func==2){
			delFirst();
		}
		else if(func==3){
			cin>>a;
			cin>>b;
			Del(a,b);
		}
		else if(func==4){
			cin>>d;
			Search(d);
		}
		else if(func==5){
			cin>>a;
			cin>>b;
			if(Search(a,b)) cout<<"True"<<endl;
			else cout<<"False"<<endl;
		}
		else if(func==6){
			
			cout<<Length()<<endl;
		}
		else{
			cout<<"Invalid Input"<<endl;
		}
	}

	return 0;
}
node* addFirst(int xnew,int ynew){
	struct node* newnode=(struct node*) malloc(sizeof(struct node));
	
		
	newnode->x=xnew;
	newnode->y=ynew;
	newnode->next=first;
	first=newnode;
	return newnode;
}
node* delFirst(){
	if(first==NULL){
		cout<<-1<<endl;
		return NULL;
	}
	struct node* newfirst=first->next;
	free(first);
	first=newfirst;
	return first;


}
int Del(int xdel,int ydel){
	if(first==NULL){
		cout<<-1<<endl;
		return -1;
	}
	if(first->x==xdel && first->y==ydel){
		delFirst();
		return 1;
	}


	node* prev=first;
	node* traverse=first->next;
	
	while(traverse!=NULL){
		if((traverse->x)==xdel && (traverse->y)==ydel){
			prev->next=traverse->next;
			free(traverse);
			return 1;
		}
		prev=traverse;
		traverse=traverse->next;
	}
	cout<<-1<<endl;
	return -1;
}
int Search(double d){
	int count=0;
	node* traverse=first;
	int xpoint,ypoint;
	double dist=0;
	while(traverse!=NULL){
		xpoint=traverse->x;
		ypoint=traverse->y;
		dist=sqrt((xpoint*xpoint)+(ypoint*ypoint));
		
		if(dist<=d){
			count++;
			//cout<<"("<<xpoint<<","<<ypoint<<") ";
		}
		traverse=traverse->next;
		

	}
	cout<<count<<endl;
	return count;


}
bool Search(int xsearch,int ysearch){
	node* traverse=first;

	while(traverse!=NULL){
		if((traverse->x)==xsearch && (traverse->y)==ysearch){
			
			return true;
		}
		traverse=traverse->next;
		

	}
	
	return false;
}
int Length(){
	node* traverse=first;
	int length=0;
	while(traverse!=NULL){
		
		traverse=traverse->next;
		length++;
		

	}
	return length;
}
void printLinkedList(){
	node* traverse=first;
	cout<<"Linked List";
	while(traverse!=NULL){
		cout<<"["<<traverse->x<<","<<traverse->y<<"]"<<"->";
		traverse=traverse->next;
	}
	cout<<endl;
}