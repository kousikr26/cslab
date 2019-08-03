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

// Karatsuba mltiplication is faster(O(n^1.58)) but works for only certain inputs(number of digits is a power of 2)
string karatsuba(string a,string b);

int main(){
	string a,b;
	cout<<"Enter 2 nums "<<endl;
	cin>>a;
	cin>>b;
	string quotient,remainder;
	tie(quotient,remainder)=divide(a,b);
	cout<<quotient<<" "<<remainder<<endl;

	return 0;
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
string karatsuba(string a,string b){

	if(a.length()<b.length()){
		string zeros(b.length()-a.length(),'0');
		a.insert(0,zeros);
	}
	else{
		string zeros(a.length()-b.length(),'0');
		b.insert(0,zeros);
	}
	int len=a.length();
	int len2=b.length();
	if(len==1 || len2==1){
		
		return to_string(stoi(a)*(stoi(b)));


	}
	string p=a.substr(0,len/2);
	string q=a.substr(len/2);
	string r=b.substr(0,len2/2);
	string s=b.substr(len/2);
	cout<<"p "<<p<<endl;
	
	string pr=mul(p,r);
	string qs=mul(q,s);
	
	string pqrs=sub(sub(mul(add(p,q),add(r,s)),pr),qs);
	cout<<"p q r s pr qs pqrs "<<p<<" "<<q<<" "<<r<<" "<<s<<" "<<pr<<" "<<qs<<" "<<pqrs<<endl;
	string halfzeros(len-(len/2),'0');
	string fullzeros(len,'0');
	pr.append(fullzeros);
	pqrs.append(halfzeros);
	cout<<"pr "<<pr<<endl;
	cout<<"pqrs2 "<<pqrs<<endl;
	string intresult=add(pr,pqrs);
	cout<<"intres "<<intresult<<endl;
	cout<<"finres "<<add(intresult,qs)<<endl;
	return add(intresult,qs);
	

}
bool isPrime(int n){
	if(n==1) return false;
	else if(n==2) return true;
	else if(n==3) return true;
	else{
		for(int i=2;i*i<=n;i++){
			if(n%i==0) return false;
		}
		return true;
	}
}
tuple<string,string> divide(string a, string b){
	string quotient="";
	string remainder="";
	const string one="1";
	
	while(true){
		
		
		if(sub(a,b)[0]=='-') break;
		else{
			
			a=sub(a,b);
			quotient=add(quotient,one);

		}
	}
	
	return {quotient,a};	

}