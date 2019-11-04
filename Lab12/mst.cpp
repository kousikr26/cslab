#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
typedef long double lld;

const int N=1e6+100;
vector<int> parent(N,0);
vector<int> ranks(N,0);
vector<int> value(N,0);
struct edge{
	int x,y;
	int w;
};
bool compare(edge e1,edge e2){
	return e1.w<e2.w;

}
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
	int n,m;
	int a,b,c;
	cin>>n>>m;
	vector<edge> graph(m+1);
	//cout<<"co";
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		edge temp;
		temp.x=a;
		temp.y=b;
		temp.w=c;
		graph[i]=temp;
		//cout<<graph[i].x<<" "<<graph[i].y<<" "<<graph[i].w<<endl;
		
	}
	cout<<"ao";
	sort(graph.begin(),graph.end(),compare);
	cout<<"bo";
	vector<edge> result;
	int product=1;
	int edges_chosen=0;
	int edge_index=0;
	cout<<"yo";
	while(edges_chosen<n-1 && edge_index<m){
		edge temp=graph[edge_index];
		if(!check_same(temp.x,temp.y)){
			result.push_back(temp);
			product*=temp.w;
			union_sets(temp.x,temp.y);
		}
	}
	cout<<product<<endl;


}