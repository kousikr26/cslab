#include <bits/stdc++.h> 
     

using namespace std;
int findDist(int x,int y);
int findMedian(int arr[],int n);
int blum(int arr[],int l,int r,int k);
int partition(int arr[],int l,int r,int pivot);
void swap(int *a, int *b);
int main(){
	int cases,n;
	cin>>cases;
	for(int i=0;i<cases;i++){
		
		
		cin>>n;
		int* radii=new int[n];
		int x,y;
		for(int j=0;j<n;j++){
			cin>>x;
			cin>>y;
			
			radii[j]=findDist(x,y);
		}
		cout<<sqrt(blum(radii,0,n-1,n/2))<<endl;

	}


	return 0;
}
int findDist(int x,int y){
	return pow(x,2)+pow(y,2);
}
int findMedian(int arr[],int n){ 
    sort(arr, arr+n);
    return arr[n/2]; 
}
int blum(int arr[],int l,int r,int k){
	if(k>0 && k<=r-l+1){
		int numelem=r-l+1;
		int numgroups=(numelem+4)/5;
		int* medians=new int[numgroups];
		int i;
		for(i=0;i<numelem/5;i++){
			medians[i]=findMedian(arr+i*5+l,5);
			
		}
		if(i*5<numelem){
			medians[i]=findMedian(arr+l+i*5,numelem%5);
			i++;
		}
		int medofmed;
		if(i==1) medofmed=medians[0];
		else{
			medofmed=blum(medians,0,i-1,i/2);
		}
		int pivotpos=partition(arr,l,r,medofmed);
		
		if(pivotpos-l==k-1) return arr[pivotpos];
		else if(pivotpos-l>k-1) return blum(arr,l,pivotpos-1,k);
		else return blum(arr,pivotpos+1,r,k-pivotpos+l-1);


	}
	else{
		cout<<"Invalid input";
		return -1;
	}
}
int partition(int arr[],int l,int r,int pivot){
	int i;
	for (i=l; i<r; i++){
		if (arr[i] == pivot) break;
	}
	swap(&arr[i], &arr[r]); 

	
	i = l;
	for (int j = l; j <= r - 1; j++)
	{ 
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	} 
	swap(&arr[i], &arr[r]);
	return i;
}
void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 