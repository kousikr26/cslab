#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
#define mod 1000000007
const int INF = 1e9;
#define fori(n) for(lli i=0;i<n;i++)
const int N=1000;
vector<vector<int>> hashedvals(N,vector<int>(1,INF));
int hash_fun(int val){
	return val%N;
}
void insert(int key){
	int hash_key=hash_fun(key);
	if(hashedvals[hash_key].size()==1 && hashedvals[hash_key][0]==INF){
		hashedvals[hash_key][0]=key;
	}
	else{
		
		hashedvals[hash_key].push_back(key);
	}

}
bool search(int key){
	int hash_key=hash_fun(key);
	if(hashedvals[hash_key].size()==1 && hashedvals[hash_key][0]==INF) return false;
	
	for(int i=0;i<hashedvals[hash_key].size();i++){
		
		if(hashedvals[hash_key][i]==key){
			
			return true;
		}
	
	}
	return false;
}
bool delete_key(int key){
	if(!search(key)) return false;
	int hash_key=hash_fun(key);
	
	vector<int>::iterator it;
	for (auto it = hashedvals[hash_key].begin(); it != hashedvals[hash_key].end(); ++it) {
		if(*it==key) break;
	}
	if(it==hashedvals[hash_key].end()) return false;
	hashedvals[hash_key].erase(it);
	return true;
}


int main(){
	insert(9000);
	insert(9023);
	insert(4000);
	insert(1000);
	
	cout<<search(4000);
	cout<<delete_key(4000);
	return 0;
}