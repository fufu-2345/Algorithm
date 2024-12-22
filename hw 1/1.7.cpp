#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a=1,b=2,find;
	int arr[n];
	int keep[1000]={0};
	int x=1;
	
	cin>>find;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i!=j){
				int sum=arr[i]+arr[j];
				if(sum==find){
					cout<<arr[i]<<" "<<arr[j]<<endl;
					x=0;
				}
				
			}
		}
	}
	
	if(x){
		cout<<-1;
	}
	
}
