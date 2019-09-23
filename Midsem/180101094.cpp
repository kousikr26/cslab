#include <bits/stdc++.h> 

using namespace std;
int main(){
	long long n,queries,a,curr,steps;
	
	cin>>n;
	cin>>queries;

	for(long long q=0;q<queries;q++){
		cin>>a;
		cin>>curr;
		if(a==1) steps=n-curr;
		else steps=curr-1;
		if(steps==0){
			cout<<1<<endl;
			break;
		}
		long long* dp=NULL;

		dp=new long long[steps+7];
		for(long long j=0;j<=steps;j++){
			dp[j]=0;
		}
		//cout<<"dp[1] "<<dp[1]<<endl;
		//cout<<"dp[3] "<<dp[3];
		dp[0]=0;
		dp[1]=0;
		dp[2]=0;
		dp[3]=1;
		dp[4]=0;
		dp[5]=1;
		dp[6]=1;
		dp[7]=1;
		for(long long j=8;j<=steps;j++){

			dp[j]=dp[j-3]+dp[j-5]+dp[j-7];
			//cout<<"j "<<j<<" dp "<<dp[j]<<" ";

		}
		//cout<<endl;
		cout<<dp[steps]%((long long)pow(10,7)+1)<<endl;


	}
}