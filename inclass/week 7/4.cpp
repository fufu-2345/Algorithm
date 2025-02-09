#include<iostream>
using namespace std;

int count=0;
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void permute(int arr[],int l,int r){
	
	if(l==r){
		bool check=false;
		for(int i=1;i<=r;i++){
			if(arr[i]==1 || arr[i]==2){
				if(i<r&& arr[i+1]==1 || arr[i+1]==2){
					count++;
				}
			}
		}
		return;
	}
	
	for(int i=l;i<=r;i++){
		swap(arr[l],arr[i]);
		permute(arr,l+1,r);
		swap(arr[l],arr[i]);
	}
}

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=1;i<=n;i++){
		arr[i]=i;
	}
	arr[0]=-1;
	
	permute(arr,1,n);
	
	
	cout<<count;
}


