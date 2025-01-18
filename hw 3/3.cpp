#include<iostream>
using namespace std;

void shellSort(int arr[],int n){
	int j=0;
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			int temp=arr[i];
			for(j=i;j>=k&&arr[j-k]>temp;j-=k){
				arr[j]=arr[j-k];
			}
			arr[j]=temp;
		}
	}
}

int main(){
	int arr[]={16,-25,2,-54,36,9,-12,66};
	int n=sizeof(arr)/sizeof(arr[0]);
	shellSort(arr,n);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
