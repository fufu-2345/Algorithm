#include<iostream>
using namespace std;

int n; 
int arr[1000];

void queen(int k){
	if(k==n){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<=n;i++){
			arr[k]=i;
			queen(k+1);
		}
	}
}


int main(){
	cin>>n;
	queen(0);
}
