#include<iostream>
using namespace std;

int n,h;
int arr[1000];
int count=0;

void print(){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<": ";
}

void present(int l,int light){
	if(light==h){
		count++;
		return;
	}
	if(l==n){
		return;
	}
	
	arr[l]=0;
	present(l+1,light);
	arr[l]=1;
	present(l+1,light+1);
	
}

int main(){
	cin>>n>>h;
	int light=0;
	
	present(0,light);
	cout<<endl<<endl<<count;
}
