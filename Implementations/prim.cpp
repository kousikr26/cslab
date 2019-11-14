#include <bits/stdc++.h>
using namespace std; 
typedef long long lli;
typedef long double lld;
#define mod 1000000007
#define fori(n) for(lli i=0;i<n;i++)
const int N=1e6;
int minKey(vector<int> keys, vector<bool> mst,vector<vector<int>> graph)  
{  
	int V=graph.size();
	int min = N;
	int min_index=0;
  
	for (int v = 0; v < V; v++)  
		if (mst[v] == false && keys[v] < min) {
			min = keys[v];
			min_index = v;
		} 
  
	return min_index;  
}
void prim(vector<vector<int>> graph)  
{  
	int V=graph.size();
	vector<int> parent(V,0);  
	  
	
	vector<int> keys(V,N);  
	  
	
	vector<bool> mst(V,false);  

  
	
	
	keys[0] = 0;  
	parent[0] = -1; 
  
	
	for (int count = 0; count < V - 1; count++) 
	{  

		int u = minKey(keys, mst,graph);  

		mst[u] = true;  
 
		for (int v = 0; v < V; v++)  
  
			if (graph[u][v]!=0 && mst[v] == false && graph[u][v] < keys[v]) {
				parent[v] = u;
				keys[v] = graph[u][v];  
			}
	}  
}
int main(){
	vector<vector<int>> graph= { { 0, 2, 0, 6, 0 },  
						{ 2, 0, 3, 8, 5 },  
						{ 0, 3, 0, 0, 7 },  
						{ 6, 8, 0, 0, 9 },  
						{ 0, 5, 7, 9, 0 } }; 


	prim(graph);
}