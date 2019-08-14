#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool checkBraces(string expression);
bool checkMatch(char a,char b);
bool isOpen(char a);
int main(){
	int testcases;
	cin>>testcases;
	string expression;
	for(int i=0;i<testcases;i++){
		cin>>expression;
		if(checkBraces(expression)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

bool checkBraces(string expression){
	int n=expression.length();
	char peekedchar;
	int pipe=0;
	stack <char> braces;
	for(int i=0;i<n;i++){
		if(expression[i]=='|' && pipe==0){
			braces.push('|');
			pipe=1;
			
		}
		else if(expression[i]=='|' && pipe==1){
			if(braces.empty()) return false;
			peekedchar=braces.top();//stack may be emptry
			
			if(checkMatch(peekedchar,expression[i])){
				
				braces.pop();
				pipe=0;

			}
			else return false;
		}
		else{
			if(isOpen(expression[i])){
				braces.push(expression[i]);
			}
			else{
				if(braces.empty()) return false;
				peekedchar=braces.top();//stack may be emptry
				if(checkMatch(peekedchar,expression[i])){
					
					braces.pop();

				}
				else{
					
					return false;
				}
			}
		}
	}
	if(braces.empty()) return true;
	else return false;
	
}
bool checkMatch(char a,char b){
	if(a=='(' && b==')') return true;
	else if(a=='[' && b==']') return true;
	else if(a=='<' && b=='>') return true;
	else if(a=='{' && b=='}') return true;
	else if(a=='|' && b=='|') return true;
	return false;

}
bool isOpen(char a){
	if(a=='<' || a=='{' || a=='[' ||a=='('){
		return true;
	}
	return false;
}