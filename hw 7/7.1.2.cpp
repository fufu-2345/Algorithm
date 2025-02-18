#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int arr[1000];

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=0;i<n;i++){
			for(int j=i;j>=k && arr[j]>arr[j-k];j-=k){
				int temp=arr[j];
				arr[j]=arr[j-k]	;
				arr[j-k]=temp;	
			}
		}
	}
}

double avg(){
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i]*(i+1);
	}
	return sum/n;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort();

	printf("\n%.2f",avg());
}
