#include<iostream>
using namespace std;

void subprint(int arr[],int l){
	cout<<"result : ";
	for(int i=1;i<=l;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void subset2(int arr[],int l,int n){
	subprint(arr,l);
	
	int j;
	l==0?j=1:j=arr[l]+1;
	
	for(int i=j;i<=n;i++){
		arr[l+1]=i;
		subset2(arr,l+1,n);
	}
}

int main(){
	int n=3,arr[n+1];
	subset2(arr,0,n);
}
