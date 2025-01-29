#include<iostream>
using namespace std;

void check(int arr[],int n,int val[],int find){
	int temp=0;
	for(int i=1;i<=n;i++){
		temp+=val[i]*arr[i];
	}
	
	if(temp==find){
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<": "<<temp<<endl;
	}
	
}

void subset(int arr[],int l,int r,int val[],int find){
	if(l==r){
		check(arr,r,val,find);
	}
	else{
		arr[l+1]=1;
		subset(arr,l+1,r,val,find);
		arr[l+1]=0;
		subset(arr,l+1,r,val,find);
	}
}

int main(){
	int n=4,find=36;
	int arr[n+1];
	int val[]={0,25,10,9,2};
	
	
	subset(arr,0,n,val,find);
}
