#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
#define INF 999999
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
void floyd(vector<vector<int>> graph){
	vector<vector<int>> dists=graph;
	int V=graph.size();
	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){ 
			for (int j = 0; j < V; j++){
			  
 
				if (dists[i][k] + dists[k][j] < dists[i][j])  
					dists[i][j] = dists[i][k] + dists[k][j];  
			}  
		}  
	}

	for (int i = 0; i < V; i++)  
	{  
	    for (int j = 0; j < V; j++)  
	    {  
	        if (dists[i][j] == INF)  
	            cout<<"INF"<<"     ";  
	        else
	            cout<<dists[i][j]<<"     ";  
	    }  
	    cout<<endl;  
	}
}
int main(){
	vector<vector<int>> graph = { {0, 5, INF, 10},  
						{INF, 0, 3, INF},  
						{INF, INF, 0, 1},  
						{INF, INF, INF, 0}  
					};
	floyd(graph);
}
