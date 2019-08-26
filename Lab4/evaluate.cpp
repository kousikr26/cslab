/* INPUT FORMAT
-NO OF TESTCASES
-NO OF EXPRESSIONS
-EXPRESSION SHOULD CONTAIN INTS AND OPERATORS +-*^/ UNARY OPERATOR AND VARIABLES 
-WORKS ONLY FOR INTS IF ANY INTERMEDIARY STEP PRODUCES A DECIMAL IT WILL BE FLOORED TO INT
-EXPONENT SHOULD NOT BE NEGATIVE AS IT WILL PRODUCE NON INT(FRACTION)
*/




#include <bits/stdc++.h> 

using namespace std;


struct et 
{ 
    string data; 
    et* left, *right; 
};


bool isOperator(char a);//CHECKS IF CHAR IS AN OPERATOR
bool isBracket(char a);//CHECKS IF CHAR IS A BRACKET
bool isDigit(char a);//CHECKS IF CHAR IS DIGIT
int isGreater(char a,char b);//COMPARES PRECEDENCE OF OPERATORS
string getString(char x);//CONVERTS CHAR TO STRING
vector <string> findPostfix(string expression);//CONVERTS INFIX TO POSTFIX
et* newNode(string v);//CREATES NEWNODE IN EXPRESSION TREE
et* constructTree(vector <string> postfix);//CONSTRUCTS EXPRESSION TREE FROM POSTFIX EXPRESSION IN VECTOR USING A STACK
void printInorder(et *t);//PRINTS TREE INORDER FOR DEBUGGING PURPOSES
int solve(et* top);//RECURSIVE FUNCTION TO SOLVE EXPRESSION TREE
string fixUnary(string a);//APPENDS A BRACKET AND 0 TO A UNARY OPERATOR
int isAssignment(string expression);//CHECKS IF EXPRESSION IS AN ASSIGNMENT STATEMENT
int evaluate(string expression);//EVALIUATES AN EXPRESSION CONTAINING NUMBERS
void assign(string expression,vector<string>& varnames,vector<string>& varvalues);//ASSIGNS A VARIABLE A VALUE FROM EXPRESSION
string substitute(string expression,vector<string>& varnames,vector<string>& varvalues);//SUBSTITUTES VALUES OF VARIABLES FROM MAP
void replaceAll( string &s, const string &search, const string &replace);//REPLACES ALL OCCURENCES OF SUBSTRING
bool invalidVariables(string expression);//CHECKS IF A STRING CONTAINS UNSUBSTITUTED VARIABLES
void updateVector(string key,string value,vector<string>& varnames,vector<string>& varvalues);
int main(){
	int testcases;
	cin>>testcases;
	for(int testcase=0;testcase<testcases;testcase++){
		int noexp;
		cin>>noexp;
		
		vector<string> varnames;
		vector<string> varvalues;
		for(int exp=0;exp<noexp;exp++){
		
			string expression;
			cin>>expression;
			if(isAssignment(expression)!=-1){
				assign(expression,varnames,varvalues);
			}
			else{
				expression=substitute(expression,varnames,varvalues);
				if(invalidVariables(expression)) cout<<"CANT BE EVALUATED"<<endl;
				else cout<<evaluate(expression)<<endl;
				
			}
		}
	}
	return 0;

}
int evaluate(string expression){
	expression.push_back(')');
	expression.insert(0,getString('('));//ENCLOSE EXPRESSION IN BRACKETS FOR EASY POSTFIX EVALUATION

	expression=fixUnary(expression);//HANDLES UNARY OPERATOR BY USING APPENDING ( AND 0


	vector <string> postfix;//VECTOR STORING POSTFIX
	postfix=findPostfix(expression);
	et* top=constructTree(postfix);
	return solve(top);
}

void assign(string expression,vector<string>& varnames,vector<string>& varvalues){
	int equalPos=isAssignment(expression);
	string finalexp;
	string substitutedString=substitute(expression.substr(equalPos+1),varnames,varvalues);
	if(invalidVariables(substitutedString)) cout<<"CANT BE EVALUATED"<<endl;
	else{
		finalexp=expression.substr(0,equalPos+1).append(to_string(evaluate(substitutedString)));
		equalPos=isAssignment(expression);
		
		updateVector(finalexp.substr(0,equalPos),finalexp.substr(equalPos+1),varnames,varvalues);
	}
	return ;
	

}
void updateVector(string key,string value,vector<string>& varnames,vector<string>& varvalues){
	for (int i=0;i<varnames.size();i++) { 
		if(varnames[i]==key){
			varvalues[i]=value;
			return;
		}
    }
    varnames.push_back(key);
    varvalues.push_back(value);
    return ; 
}
string substitute(string expression,vector<string>& varnames,vector<string>& varvalues){
	
    for (int i=0;i<varnames.size();i++) { 
		replaceAll(expression,varnames[i],varvalues[i]);
    } 
    return expression;

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

	string temp(""); 
	bool parsingInteger=false;
	
	for(int i=0;i<expression.length();i++){
		char curr=expression[i];
		if(isDigit(curr)){
			temp.push_back(curr);
			parsingInteger=true;
		}
		else if(isOperator(curr) || isBracket(curr)){
			
			if(parsingInteger){
				postfix.push_back(temp);
				temp.clear();
				parsingInteger=false;
			}

			
			if(curr=='('){
				s.push(curr);
				
			}
			else if(curr==')'){
				while(s.top()!='('){
					postfix.push_back(getString(s.top()));
					
					s.pop();
				}
				s.pop();//pop the (

			}

			else if(s.empty()||s.top()=='('||(isGreater(curr,s.top())>0)){
				
				s.push(curr);
			}
			else{
				
				while(s.top()!='('&&(isGreater(s.top(),curr)>=0)){
					
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
string fixUnary(string a){
	char prev;
	char curr;
	int index;
	bool present;
	do{
		present=false;
		for(int i=1;i<a.length();i++){
			curr=a[i];
			prev=a[i-1];
			if(curr=='-'&&(prev=='(' || isOperator(prev))){
				present=true;
				index=i;
				while(isDigit(a[++i]));


				a.insert(index,getString('('));
				a.insert(index+1,getString('0'));
				a.insert(i+2,getString(')'));
				break;
			}
		}
	}
	while(present);
	return a;
}
int isAssignment(string expression){
	for(int i=0;i<expression.length();i++){
		if(expression[i]=='=') return i;
	}
	return -1;
}
void replaceAll( string &s, const string &search, const string &replace ) {
    for( size_t pos = 0; ; pos += replace.length() ) {
        // Locate the substring to replace
        pos = s.find( search, pos );
        if( pos == string::npos ) break;
        // Replace by erasing and inserting
        s.erase( pos, search.length() );
        s.insert( pos, replace );
    }
}
bool invalidVariables(string expression){
	for(int i=0;i<expression.length();i++){
		if(isalpha(expression[i])) return true;
	}
	return false;
}