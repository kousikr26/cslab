#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
void rec(vector<vector<int>> graph,vector<bool> &visited,int v){
	visited[v]=true;
	cout<<v<<" ";
	for(int i=0;i<graph[v-1].size();i++){
		if(!visited[graph[v-1][i]]){
			
			rec(graph,visited,graph[v-1][i]);
			
		}
	}
}
void dfs(vector<vector<int>> graph){
	vector<bool> visited(graph.size()+1,false);
	int v=1;
	
	rec(graph,visited,v);

}
int main(){
	vector<vector<int>> graph={{2,3},{1,4,5},{1,5},{2,5,6},{2,3,4,6},{4,5}};
	dfs(graph);
	cout<<endl;
	vector<vector<int>> graph2={{2,4,9},{1,8},{4,6,8},{1,5,9},{4,9},{3,7},{6},{2,3},{1,5}};
	dfs(graph2);
}