#include <bits/stdc++.h> 
#define lli long long;
using namespace std;

int colorGraph(vector<vector<int>> graph, set<int> &vertices,int start, int n){
	vector<int> visited(n+1,0);
	vector<int> colors(n+1,0);
	queue<int> bfs;
	bfs.push(start);
	visited[start]=1;
	int popvalue;
	int currentColor=1;
	colors[start]=currentColor;
	bool possible=true;
	while(!(bfs.empty())){
		popvalue=bfs.front();
		//cout<<"POP "<<popvalue<<endl;
		bfs.pop();
		visited[popvalue]=1;
		vertices.erase(popvalue);
		currentColor=colors[popvalue];
		for(int i=0;i<graph[popvalue].size();i++){
			//cout<<"at "<<popvalue<<" visiting "<<graph[popvalue][i]<<" color "<<colors[graph[popvalue][i]]<<" curr color "<<currentColor<<endl;
			if(colors[graph[popvalue][i]]==currentColor){
				possible=false;
				
				return 0;
				break;
			}
			if(visited[graph[popvalue][i]]==0){
				bfs.push(graph[popvalue][i]);
				
				colors[graph[popvalue][i]]=3-currentColor;
			}
		}
		if(!possible){
			break;
		}
		
	}
	
	return 1;



}




int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int>> graph;
	set<int> vertices; 
	graph.resize(n+1, vector<int>(0));
	for(int i=0;i<m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		vertices.insert(a);
		vertices.insert(b);

	}
	// for(int i=1;i<=3;i++){
	// 	cout<<graph[i][0]<<" "<<graph[i][1]<<endl;

	// }
	int check=1;
	while(vertices.size()!=0){
		if(colorGraph(graph,vertices,*vertices.begin(),n)==0){
			cout<<"NO"<<endl;
			check=0;
			break;
		}
	}
	if(check==1) cout<<"YES"<<endl;

}
/*testcase
6 7
1 2
2 3
3 4
4 5
5 6
6 1
6 2

*/