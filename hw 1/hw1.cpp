#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int a=1,b=2,find;
	int arr[n];
	int keep[1000]={0};
	int x=1;
	
	cout<<"Enter the data: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	
	cout<<"Enter where you find: ";
	cin>>find;
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i!=j){
				int sum=arr[i]+arr[j];
				if(sum==find){
					cout<<arr[i]<<" + "<<arr[j]<<" = "<<sum<<endl;
					x=0;
				}
				
			}
		}
	}
	
	if(x){
		cout<<"not found";
	}
	
}
