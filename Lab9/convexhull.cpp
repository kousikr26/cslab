#include <bits/stdc++.h> 
     
#define ll long long;
using namespace std;
typedef struct {
	int x, y;
} point;


bool minx(point p1,point p2);
void swap(point* p1, point* p2);
int findOrientation(point p,point q,point r);
bool compPolar(point p, point q);
int eucDist(point p, point q);
point belowTop(stack <point> &pointStack);


point pivot;

int main(){

	int t;
	cin>>t;
	point points[t];
	int tempx,tempy;
	for(int i=0;i<t;i++){
		cin>>tempx>>tempy;
		point tempPoint={tempx,tempy};
		points[i]=tempPoint;
	}
	

	point* i1=min_element(points,points+t,minx);
	swap(points[0],points[i1-&points[0]]);
	
	pivot=points[0];

	sort(points+1,points+t,compPolar);





	int n=1;
	for(int i=1;i<t;i++){
		while(i<t-1 && findOrientation(pivot,points[i],points[i+1])==0) i++;
		points[n]=points[i];
		n++;
	}

	
	
	if(n<3) cout<<0<<endl;
	else{
		stack <point> pointStack;
		pointStack.push(points[0]);
		pointStack.push(points[1]);
		pointStack.push(points[2]);
		
		for(int i=3;i<n;i++){
			//cout<<"iteration"<<i<<"val "<<findOrientation(belowTop(pointStack),pointStack.top(),points[i])<<endl;
			while(findOrientation(belowTop(pointStack),pointStack.top(),points[i]) !=1 ){
				//cout<<"inside while "<<belowTop(pointStack).x<<belowTop(pointStack).y<<" "<<pointStack.top().x<<","<<pointStack.top().y<<" "<<points[i].x<<","<<points[i].y<<endl;
				pointStack.pop();
			}
			pointStack.push(points[i]);
		}
		stack <point> reverseStack;
		int count=0;
		while(!pointStack.empty()){
			point temp=pointStack.top();
			pointStack.pop();
			reverseStack.push(temp);
			count++;
		}
		cout<<count<<endl;
		while(!reverseStack.empty()){
			cout<<reverseStack.top().x<<" "<<reverseStack.top().y<<endl;
			reverseStack.pop();
		}
	}

	

}
bool minx(point p,point q){
	if(p.x==q.x) return p.y<q.y;
	
	else return p.x<q.x;
}
int swap(point &p, point &q){ 
    point temp = p; 
    p = q; 
    q = temp; 
}
int findOrientation(point p,point q,point r){
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if(val==0) return 0;
	else if(val>0) return 1;
	else return -1;
}
bool compPolar(point p, point q){
	int val=findOrientation(pivot,p,q);
	if(val==0){
		return eucDist(pivot,p)<=eucDist(pivot,q);
	}
	else if(val==1) return true;
	else return false;
}
int eucDist(point p, point q){
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y); 
}
point belowTop(stack <point> &pointStack){
	point temp=pointStack.top();
	pointStack.pop();
	point temp2=pointStack.top();
	pointStack.push(temp);
	return temp2;
}
