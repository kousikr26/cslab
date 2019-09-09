#include <bits/stdc++.h> 
#include <string>

using namespace std;
bool compare(string a, string b);
void mergeSort(int p, int q, string arr[]);
void merge(int p, int mid,int q, string arr[]);

int main(){
	int cases,t;
	cin>>cases;
	for(int i=0;i<cases;i++){
		cin>>t;
		string* vals=NULL;
		vals=new string[t];
		for(int j=0;j<t;j++){
			cin>>vals[j];
		}
		sort(vals,vals+t,compare);
		for(int k=0;k<t;k++){
			cout<<vals[k];
		}
		cout<<endl;

	}


	return 0;
}

bool compare(string a, string b){
	string ab(a);
	string ba(b);
	ab.append(b);
	ba.append(a);
	if(ab.length()>ba.length()) return true;
	else if(ba.length()>ab.length()) return false;
	else{
		for(int i=0;i<ab.length();i++){
			if(ab[i]>ba[i]) return true;
			else if(ba[i]>ab[i]) return false;
		}
		return true;
	}
}
void mergeSort(int p, int q, string arr[]){
	if(p<q){
		int mid=(p+q)/2;
		mergeSort(p,mid,arr);
		mergeSort(mid+1,q,arr);
		merge(p,mid,q,arr);
	}
	return ;
}
void merge(int p, int mid,int q, string arr[]){
	int n1=mid-p+1;
	int n2=q-mid;
	string left[n1];
	string right[n2];
	for(int iter=0;iter<=mid;iter++){
		left[iter]=arr[iter];

	}
	for(int iter=mid+1;iter<=q;iter++){
		right[iter-mid-1]=arr[iter];
		
	}
	int i=0,j=0,k=0;
	while(i<n1 && j<n2){
		if(compare(left[i],right[j])){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;

	}
	while(i<n1){
		arr[k]=left[i];
		i++;
		k++;

	}
	while(j<n2){
		arr[k]=right[j];
		j++;
		k++;
	}

}