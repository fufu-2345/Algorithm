#include<iostream>
#include<cmath>
using namespace std;

int n,m;
int arr[1000];
int count=0;

void print(){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	count++;
}

void queen(int k){
	if(k==n){
		if(arr[1]>arr[0]){
			print();	
		}
		return;
	}
	
	for(int r=1;r<m+1;r++){
		arr[k]=r;
		queen(k+1);	
	}
	
}

int main(){
	cin>>m>>n;
	queen(0);
	cout<<count;
	
}
