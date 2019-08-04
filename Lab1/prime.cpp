#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include <tuple>
using namespace std;


string add(string a,string b);
string mul(string a,string b);
string sub(string a,string b);
tuple<string,string>  divide(string a, string b);
bool isPrime(int n);
string digitmul(string a,char b);
string stripzeros(string a);

bool isPrime(string n){
	if(n==string("1")) return false;
	else if(n==string("2")) return true;
	else if(n==string("3")) return true;
	
	else{
		string iterator="2";
		while(sub(n,mul(iterator,iterator))[0]!='-'){
			
			string q,r;
			tie(q,r)=divide(n,iterator);
			r=stripzeros(r);
			
			if(r==string("0")){
				
				return false;
			}
			iterator=add(iterator,string("1"));
		}
		
		return true;
	}
	
}
int main(){
	string n;
	int testcases;
	cin>>testcases;
	for(int i=0;i<testcases;i++){
		cin>>n;
		if(isPrime(n)) cout<<"Prime"<<endl;
		else cout<<"Not Prime"<<endl;
	}

}

string add(string a,string b){
	string result;
	if(a.length()<b.length()){
		string zeros(b.length()-a.length(),'0');
		a.insert(0,zeros);
	}
	else{
		string zeros(a.length()-b.length(),'0');
		b.insert(0,zeros);
	}
	result="";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry=0;
	int sum;


	for(int i=0;i<a.length();i++){
		sum=a[i]-'0'+b[i]-'0'+carry;

		carry=0;
		if(sum>9){
			result.append(to_string(sum-10));
			carry=1;
		}
		else{
			result.append(to_string(sum));
		}
	}
	if(carry!=0) result.append(to_string(carry));
	reverse(result.begin(), result.end());
	return result;

}
string sub(string a,string b){
	string result;
	if(a.length()<b.length()){
		string zeros(b.length()-a.length(),'0');
		a.insert(0,zeros);
	}
	else{
		string zeros(a.length()-b.length(),'0');
		b.insert(0,zeros);
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(), b.end());
	int carry=0;
	int sum;
	
	
	for(int i=0;i<a.length();i++){
		sum=(a[i]-'0')-(b[i]-'0')-(carry);
		
		
		if(sum<0){
			result.append(to_string(sum+10));
			carry=1;
		}
		else{
			carry=0;
			result.append(to_string(sum));
		}
	}
	if(carry!=0){ 
		string minus="-";
		reverse(a.begin(),a.end());
		reverse(b.begin(), b.end());
		return minus.append(sub(b,a));
	}
	reverse(result.begin(), result.end());
	return result;

}
string mul(string a, string b){
	string result="";
	string tempres="";
	reverse(b.begin(),b.end());
	for(int i =0;i<b.length();i++){
		string zeros(i,'0');
		tempres=digitmul(a,b[i]);
		tempres.append(zeros);
		
		result=add(result,tempres);
	}
	return result;


}
string digitmul(string a,char b){
	string result="";
	int bval=b-'0';
	int carry=0;
	int prod;
	reverse(a.begin(),a.end());
	for(int i =0;i<a.length();i++){
		prod=(a[i]-'0')*bval+carry;
		carry=0;
		if(prod>9){
			carry=prod/10;
			result.append(to_string(prod%10));
		}
		else{
			result.append(to_string(prod));	
		}
	}
	if(carry!=0) result.append(to_string(carry));
	reverse(result.begin(), result.end());
	return result;
}
tuple<string,string> divide(string a, string b){
	string quotient="";
	string remainder="";
	const string one="1";
	int al=a.length();
	int bl=b.length();
	if((al-bl-1) >= 1){
		
		quotient="1";
		quotient.append(string(a.length()-b.length()-1,'0'));

		a=sub(a,mul(quotient,b));
	}
	while(true){
		
		
		if(sub(a,b)[0]=='-') break;
		else{
			
			a=sub(a,b);
			quotient=add(quotient,one);

		}
	}
	
	return {quotient,a};	

}
string stripzeros(string a){
	
	for (int i=0;i<a.length();i++){
		
		if(a[i]!='0'){
			
			return a.substr(i);
		}
		
	}
	return string("0");
}