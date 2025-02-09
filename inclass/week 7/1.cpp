#include<iostream>
using namespace std;

void check(int arr[],int n,int* best,int val[],int w[],int maxW){
	int temp=0,wCheck=0;
	for(int i=1;i<=n;i++){
		wCheck+=w[i]*arr[i];
		temp+=val[i]*arr[i];
	}
	if(wCheck<=maxW){
		if(temp>*best){
			*best=temp;
		}
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<": "<<temp<<endl;
	}
	
}

void subset(int arr[],int l,int r,int* best,int val[],int w[],int maxW){
	if(l==r){
		check(arr,r,&(*best),val,w,maxW);
	}
	else{
		arr[l+1]=1;
		subset(arr,l+1,r,&(*best),val,w,maxW);
		arr[l+1]=0;
		subset(arr,l+1,r,&(*best),val,w,maxW);
	}
}

int main(){
	int n=4,best=0,maxW=13;
	int arr[n+1];
	int val[]={0,10,20,25,8};
	int w[]={0,5,3,8,4};
	
	
	subset(arr,0,n,&best,val,w,maxW);
	cout<<"--------------------------------"<<endl<<best;
}
