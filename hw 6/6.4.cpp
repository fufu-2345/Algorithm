#include<iostream>
#include<cmath>
using namespace std;

int n;
int arr[1000];
int count=0;

void print(int l){
	count++;
	if(l==0){
		cout<<"0"<<endl;
		return;
	}
	for(int i=1;i<l+1;i++){
		cout<<arr[i];
	}
	cout<<endl;
}

void subset(int l){
	print(l);
	int j;
	if(l==0){
		j=1;
	}
	else{
		j=arr[l]+1;	
	}
	for(int i=j;i<n+1;i++){
			arr[l+1]=i;
			subset(l+1);
		}
	
}

int main(){
	cin>>n;
	subset(0);
	
	cout<<count;
	
}
