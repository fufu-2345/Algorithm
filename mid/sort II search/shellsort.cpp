#include<iostream>
using namespace std;


void sort(int arr[],int n){
	for(int k=n/2;k>0;k/=2){
		for(int i=0;i<n;i++){
			for(int j=i;j>=k && arr[j]<arr[j-k];j-=k){
				int temp=arr[j];
				arr[j]=arr[j-k]	;
				arr[j-k]=temp;			
			}
		}
	}
}

int main(){
	int arr[]={10,9,5,54,321,-999,0,7,2,9,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}
