#include<iostream>
using namespace std;

int par(int arr[],int l,int r){
	int i=l,j=r, pivot=arr[(l+r)/2];
	while(i<j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if (i <= j) { 
            int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
        }
	
	}
	return i;
}

int quickSort(int arr[],int l,int r){
	if(l<r){
		int s=par(arr,l,r);
		quickSort(arr,l,s-1);
		quickSort(arr,s,r);
	}
}

int main(){
	int arr[]={10,9,5,54,321,-999,0,7,2,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	quickSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}
