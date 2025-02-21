#include<iostream>
using namespace std;

int n;

int main(){
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int now=-2;
	int sum=0;
	while(now+2<n){
		if(now+3==n){
			now+=2;
			sum+=arr[now];
			break;
		}
		else{
			if(arr[now+2]>arr[now+3]){
				now+=2;
				sum+=arr[now];
			}
			else{
				now+=3;
				sum+=arr[now];
			}
		}
	}
	cout<<sum;
}
