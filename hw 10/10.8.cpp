#include<iostream>
#include<stdio.h>
using namespace std;

int n;

double cal(double memo[],int now,int arr[]){
	if(now==0){
		return 0;
	}
	if(memo[now]!=0){
		return memo[now];
	}
	memo[now]=((cal(memo,now-1,arr)*(now-1))+arr[now-1])/now;
	return memo[now];
}

int main(){
	cin>>n;
	double memo[n+1]={0};
	int arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	memo[1]=arr[0];
	printf("\n\n%.2f",cal(memo,n,arr));
}
