#include <bits/stdc++.h> 
#define lli long long;
using namespace std;

int traverse(vector<vector<int>> graph,vector<vector<int>> &seen,int x, int y, int color);
int find(vector<vector<int>> graph,vector<vector<int>> seen);
int main(){
	int m,n,c;
	cin>>m>>n>>c;
	vector<vector<int>> graph;
	vector<vector<int>> seen;
	graph.resize(m, vector<int>(n, 0));
	seen.resize(m, vector<int>(n, 0));

	//graph[0][0]=0;
	//cout<<m<<n<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//cout<<"ij "<<i<<" "<<j<<endl;
			cin>>graph[i][j];
		}
	}
	//cout<<"yo"<<endl;
	cout<<find(graph,seen)<<endl;

	return 0;
}
int traverse(vector<vector<int>> graph,vector<vector<int>> &seen,int x, int y, int color){
	
	int m=graph.size();
	int n=graph[0].size();
	int res=1;
	//cout<<"bo "<<x<<" "<<y<<" "<<res<<endl;
	seen[x][y]=1;
	if(x<m-1 && !seen[x+1][y] && graph[x+1][y]==color) {
		
		res+=traverse(graph,seen,x+1,y,color);
	}
	if(y<n-1 && !seen[x][y+1] && graph[x][y+1]==color) {
		
		res+=traverse(graph,seen,x,y+1,color);
	}
	if(x>0 && !seen[x-1][y] && graph[x-1][y]==color) {
		
		res+=traverse(graph,seen,x-1,y,color);
	}
	if(y>0 && !seen[x][y-1] && graph[x][y-1]==color) {
		
		res+=traverse(graph,seen,x,y-1,color);
	}
	return res;
}
int find(vector<vector<int>> graph,vector<vector<int>> seen){
	int size=0;
	int max_size=0;

	for(int i=0;i<graph.size();i++){
		for(int j=0;j<graph[0].size();j++){
			if(!seen[i][j]){
				size=traverse(graph,seen,i,j,graph[i][j]);
				if(size>max_size){
					max_size=size;
				}
			}
		}
	}
	return max_size;
}