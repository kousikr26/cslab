#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

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
int main(){
	string a,b;
	int testcases;
	cin>>testcases;
	for(int i=0;i<testcases;i++){
		cin>>a;
		cin>>b;
		cout<<sub(a,b)<<endl;
	}

}