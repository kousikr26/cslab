#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define fori(n) for(lli i=0;i<n;i++)
bool binarySearch(vector<string> arr,int l, int r,string x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        if (arr[mid] == x) 
            return true; 

        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  

        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return false; 
}

int main(){
	int n;
	cin>>n;
	vector<string> inps;
	string temp,revstr;
	for(int i=0;i<n;i++){
		cin>>temp;
		revstr=temp;
		reverse(revstr.begin(),revstr.end());
		
		if(temp!=revstr){
			inps.push_back(temp);
			
		}
			
	}
	sort(inps.begin(),inps.end());
	
	cout<<endl;	
	bool con=false;
	for(int i=0;i<inps.size();i++){
		temp=inps[i];
		revstr=temp;
		reverse(revstr.begin(),revstr.end());
		

		if(binarySearch(inps,0,inps.size()-1,temp)){
			if(binarySearch(inps,0,inps.size()-1,revstr)){con=true;break;}
			
		}

	}
	if(con) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}