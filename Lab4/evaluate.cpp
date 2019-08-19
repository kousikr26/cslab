/* INPUT FORMAT
-NO OF TESTCASES
-NO OF EXPRESSIONS
-EXPRESSION CONTAINING INTS AND OPERATORS +-*^/

*/



#include <iostream>
#include<string>
#include <stack>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;


struct et 
{ 
    string data; 
    et* left, *right; 
};


bool isOperator(char a);
bool isBracket(char a);
bool isDigit(char a);
int isGreater(char a,char b);
string getString(char x);
vector <string> findPostfix(string expression);
et* newNode(string v);
et* constructTree(vector <string> postfix);
void printInorder(et *t);
int solve(et* top);



int main(){
	int testcases;
	cin>>testcases;
	for(int testcase=0;testcase<testcases;testcase++){
		int noexp;
		cin>>noexp;
		for(int exp=0;exp<noexp;exp++){
		
			string expression;
			cin>>expression;
			expression.push_back(')');
			expression.insert(0,getString('('));

			vector <string> postfix;
			postfix=findPostfix(expression);
			et* top=constructTree(postfix);
			//printInorder(top);
			//cout<<endl;
			cout<<solve(top);
			cout<<endl;
		}
	}
	return 0;

}


et* newNode(string v) { 
    et *temp = new et; 
    temp->left = NULL;
    temp->right = NULL;
    temp->data = v; 
    return temp; 
};

et* constructTree(vector <string> postfix){ 
    stack<et *> nodestack; 
    et *t, *rightnode, *leftnode; 

    for (int i=0; i<postfix.size(); i++) 
    { 
         
        if (!isOperator(postfix[i][0])) 
        { 
            t = newNode(postfix[i]); 
            nodestack.push(t); 
        } 
        else 
        { 
            t = newNode(postfix[i]); 
            rightnode = nodestack.top();
            nodestack.pop(); 
            leftnode = nodestack.top(); 
            nodestack.pop(); 
  
            
            t->right = rightnode; 
            t->left = leftnode; 
  
           
            nodestack.push(t); 
        } 
    } 

    t = nodestack.top(); 
    nodestack.pop(); 
  
    return t; 
}

void printInorder(et *t){ 
    if(t) 
    { 
        printInorder(t->left); 
        cout<<t->data<<" "; 
        printInorder(t->right); 
    } 
}
int solve(et* top){
	if(top==NULL) return 0;
	if(!isOperator((top->data)[0])){
		return stoi(top->data);
	}

	int leftval=solve(top->left);
	int rightval=solve(top->right);
	if((top->data)[0]=='+') return leftval+rightval;
	else if((top->data)[0]=='-') return leftval-rightval;
	else if((top->data)[0]=='*') return leftval*rightval;
	else if((top->data)[0]=='/') return leftval/rightval;
	else if((top->data)[0]=='^') return (int)pow(leftval,rightval);
	else{
		cout<<"invalid char found"<<endl;
		return -1;
	}
}

vector <string> findPostfix(string expression){
	stack <char> s;
	vector <string> postfix;

	string temp(""); //REmember to clear after pushing
	bool parsingInteger=false;//remember to reset
	//cout<<isGreater('+','*')<<endl;
	for(int i=0;i<expression.length();i++){
		char curr=expression[i];
		if(isDigit(curr)){
			temp.push_back(curr);
			parsingInteger=true;
		}
		else if(isOperator(curr) || isBracket(curr)){
			//cout<<"coi"<<curr<<" "<<s.top()<<" "<<endl;
			if(parsingInteger){
				postfix.push_back(temp);
				temp.clear();
				parsingInteger=false;
			}

			
			if(curr=='('){
				s.push(curr);
				//cout<<"boi"<<curr<<endl;
			}
			else if(curr==')'){
				while(s.top()!='('){
					postfix.push_back(getString(s.top()));
					//cout<<"aoi"<<endl;
					s.pop();
				}
				s.pop();//pop the (

			}

			else if(s.empty()||s.top()=='('||(isGreater(curr,s.top())>0)){
				//cout<<"doi"<<endl;
				s.push(curr);
			}
			else{
				//cout<<"eoi"<<endl;
				while(s.top()!='('&&(isGreater(s.top(),curr)>=0)){
					//cout<<"foi"<<s.top()<<" "<<curr<<endl;
					postfix.push_back(getString(s.top()));
					s.pop();
				}
				s.push(curr);
			}

			
		}
		else{
			cout<<"invalidchar"<<endl;
		}
	}
	/*
	for(int j=0;j<postfix.size();j++){
		cout<<postfix[j]<<" ";
	}

	cout<<endl;
	*/
	return postfix;
}
bool isOperator(char a){
	if(a=='+'||a=='*'||a=='-'||a=='/'||a=='^') return true;
	return false;

}

bool isBracket(char a){
	if(a=='(' || a==')') return true;
	return false;
}
bool isDigit(char a){
	if(a>='0' && a<='9') return true;
	return false;
}
int isGreater(char a,char b){
	if(!isOperator){
		cout<<"Operator not passed"<<endl;
		return -1;
	}
	else{
		if(a=='^') return 1;
		if(b=='^') return -1;
		if(a=='*'||a=='/'){
			if(b=='+'||b=='-') return 1;
			else return 0;
		}
		if(a=='+'||a=='-'){
			if(b=='*'||b=='/') return -1;
			else return 0;
		}
	}

}
string getString(char x) 
{ 

    string s(1, x); 
  
    return s;    
}