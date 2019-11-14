#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
typedef long double lld;
#define mod 1000000007
#define fori(n) for(lli i=0;i<n;i++)
const int N=1e6+100;
vector<lli> parent(N);
vector<lli> ranks(N);
vector<lli> value(N);
struct edge{
	lli x,y;
	lli w;
};
bool compare(edge e1,edge e2){
	return e1.w<e2.w;

}
lli find_set(lli val){
	
	vector<lli> A;
	while(val != parent[val])
	{
	    A.push_back(val);
	    val = parent[val];
	}
	for(lli i=0; i < A.size(); i++) 
		parent[A[i]] = val;
	return val;

}
lli make_set(lli val){
	parent[val]=val;
	ranks[val]=0;
}
bool check_same(lli a, lli b){
	if(find_set(a)==find_set(b)) return true;
	return false;

}
void union_sets(lli a ,lli b){
	a=find_set(a);
	b=find_set(b);
	if(ranks[a] > ranks[b])
	{
	    parent[b] = a;
	}
	else if(ranks[a] < ranks[b])
	{
	    parent[a] = b;
	} 
	else 
	{    
	    parent[b] = a;
	    ranks[a] += 1;
	}
	
		

}
int main(){
	lli n,m;
	lli a,b,c;
	cin>>n>>m;
	vector<edge> graph(m);
	//cout<<"co";
	for(lli i=0;i<m;i++){
		cin>>a>>b>>c;
		
		graph[i].x=a;
		graph[i].y=b;
		graph[i].w=c;
		

		//cout<<graph[i].x<<" "<<graph[i].y<<" "<<graph[i].w<<endl;
		
	}
	
	sort(graph.begin(),graph.end(),compare);
	
	
	lli weight_sum=0;

	
	fori(n){
		make_set(i);
	}
	fori(m){
		
		
		if(!check_same(graph[i].x,graph[i].y)){
			
			weight_sum=((weight_sum)%mod+(graph[i].w)%mod)%mod;
			union_sets(graph[i].x,graph[i].y);
			
		}
		
	}
	cout<<weight_sum<<endl;


}