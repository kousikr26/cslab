#include <bits/stdc++.h> 

using namespace std;
int findMax(vector<int> amounts);
int main(){
	int nusers,nqueries,operation,amount,userid;

	cin>>nusers;
	cin>>nqueries;
	vector<int> users;
	vector<int> amounts;
	
	for(int query=0;query<nqueries;query++){
		cin>>operation;
		
		if(operation==1){
			cin>>userid;
			cin>>amount;
			bool present=false;
			int index=0;
			
			for(;index<users.size();index++){
				if(users[index]==userid){
					present=true;
					break;
				}
			}
			if(present){
				amounts[index]=amounts[index]+amount;
			}
			else{
				users.push_back(userid);
				amounts.push_back(amount);
				
			}

		}
		else if(operation==2){
			int maxindex=findMax(amounts);
			if(maxindex==-1) cout<<"No data available."<<endl;
			else{
				cout<<users[maxindex]<<endl;
			}
		}
		else cout<<"Invalid operation";
	}
}
int findMax(vector <int> amounts){
	int max=-1;
	int maxindex=-1;
	for(int i=0;i<amounts.size();i++){
		if(amounts[i]>max){
			max=amounts[i];
			maxindex=i;
		}
	}
	return maxindex;
}