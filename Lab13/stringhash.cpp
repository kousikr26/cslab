#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define fori(n) for(lli i=0;i<n;i++)
const int p=53;
const int m=1e7+19;

lli hash_func(string const& s) {
    
    
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'A' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
int main(){
	int n;
	cin>>n;
	vector<string> inps;
	
	vector<vector<string>> hashTable(m);


	string temp,revstr;
	

	for(int i=0;i<n;i++){
		cin>>temp;
		revstr=temp;
		reverse(revstr.begin(),revstr.end());
		
		if(temp!=revstr){
			hashTable[hash_func(temp)].push_back(temp);
			inps.push_back(temp);
		}

			
	}
	bool con=false;
	for(int i=0;i<inps.size();i++){
		temp=inps[i];
		revstr=temp;
		reverse(revstr.begin(),revstr.end());
		

		if(hashTable[hash_func(revstr)].size()!=0){
			for(int i=0;i<hashTable[hash_func(revstr)].size();i++){
				if(hashTable[hash_func(revstr)][i]==revstr){
					con=true;
					break;
				}
			}

		}


	}

	if(con) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}