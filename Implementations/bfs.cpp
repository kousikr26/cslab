#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
void bfs(vector<vector<int>> graph){
	vector<bool> visited(graph.size()+1,false);
	queue<int> q;
	q.push(1);
	int v;
	while(!q.empty()){
		v =q.front();
		q.pop();
		visited[v]=true;
		cout<<v<<" ";
		for(int i=0;i<graph[v-1].size();i++){
			if(!visited[graph[v-1][i]]) {q.push(graph[v-1][i]);visited[graph[v-1][i]]=true;}

		}
	
	}
}
int main(){
	vector<vector<int>> graph={{2,3},{1,4,5},{1,5},{2,5,6},{2,3,4,6},{4,5}};
	bfs(graph);
	cout<<endl;
	vector<vector<int>> graph2={{2,4,9},{1,8},{4,6,8},{1,5,9},{4,9},{3,7},{6},{2,3},{1,5}};
	bfs(graph2);
}