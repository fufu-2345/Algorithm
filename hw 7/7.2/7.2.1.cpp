#include<iostream>
using namespace std;

int n;
int arr[1001];
int a=0,b=0;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>=k && arr[j]>arr[j-k];j-=k){
				swap(arr[j],arr[j-k]);
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	sort();
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;

	for(int i=0;i<n;i++){
		if(a<=b){
			a+=arr[i];
		}
		else{
			b+=arr[i];
		}
	}
	
	if(a>b){
		cout<<a-b;
	}
	else{
		cout<<b-a;
	}
}
