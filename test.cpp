#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
string add(string a,string b);
string mul(string a,string b);
string sub(string a,string b);
int main(){
	string a,b;
	cin>>a;
	cin>>b;

	//cout<<add(a,b);
	cout<<mul(a,b)<<endl;
	//cout<<sub(a,b);
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
	result="";
	reverse(a.begin(), a.end());
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
	if(carry!=0) result.append(to_string(carry));
	reverse(result.begin(), result.end());
	return result;

}
string mul(string a,string b){
	int len=a.length();
	int len2=b.length();
	if(len==1 || len2==1){
		
		return to_string(stoi(a)*(stoi(b)));


	}
	string p(a,0,len/2);
	string q(a,(len/2),len/2);
	string r(b,0,len/2);
	string s(b,(len/2),len/2);
	
	
	string pr=mul(p,r);
	string qs=mul(q,s);
	
	string pqrs=sub(sub(mul(add(p,q),add(r,s)),pr),qs);
	
	string halfzeros(len/2,'0');
	string fullzeros(len,'0');
	pr.append(fullzeros);
	pqrs.append(halfzeros);
	
	string intresult=add(pr,pqrs);
	return add(intresult,qs);
	

}