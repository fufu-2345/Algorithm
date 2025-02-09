#include<iostream>
using namespace std;

int n;
int arr[1000];
int best=-1;

void jump(int l,int sum){
	if(l==n || l==n-1){
		if(sum>best){
			best=sum;
		}
		return;
	}
	if(l+1<=n){
		jump(l+2,sum+arr[l+2]);
	}
	if(l+2<=n){
		jump(l+3,sum+arr[l+3]);
	}
}

int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	jump(-2,0);
	
	cout<<endl<<endl<<best;
}
