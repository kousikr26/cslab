#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
const int N=1e6+100;
int parent[N];
int ranks[N];
int value[N];
int find_set(int val){
	if(parent[val]==val) return val;
	else return parent[val]=find_set(val);

}
int make_set(int val){
	parent[val]=val;
	ranks[val]=0;
}
bool check_same(int a, int b){
	if(find_set(a)==find_set(b)) return true;
	return false;

}
int union_sets(int a ,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(ranks[a]==ranks[b]) ranks[b]++;
		if(ranks[a]<=ranks[b]){
			parent[a]=b;
			return b;
		}
		else {
			parent[b]=a;
			return a;
		}
	}
		

}
int main(){
	return 0;
}