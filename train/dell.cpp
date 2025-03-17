#include<iostream>
using namespace std;

int arr[]={10,9,-1,-5,3,4,6,7,-3};
int n=sizeof(arr)/sizeof(arr[0]);

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>=k && arr[j]<arr[j-k];j-=k){
				swap(arr[j],arr[j-k]);
			}
		}
	}	
}

int main(){
	sort();
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
