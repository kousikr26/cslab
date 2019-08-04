#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

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


int main(){
	string a,b;
	int testcases;
	cin>>testcases;
	for(int i=0;i<testcases;i++){
		cin>>a;
		cin>>b;
		cout<<mul(a,b)<<endl;
	}

}