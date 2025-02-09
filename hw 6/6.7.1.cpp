#include<iostream>
using namespace std;

int n;
int arr[1000];
int a[1000];
int b[1000];
int best=(1LL<<31)-1;

void print(){
	for(int i=1;i<n+1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<": ";
}

void sum(){
	int l=0,r=0;
	for(int i=0;i<n;i++){
		if(arr[i+1]==0){
			l+=a[i];
			r+=b[i];
		}
		else{
			l+=b[i];
			r+=a[i];
		}
	}
	
	if(l>=r){
		cout<<l-r<<endl;
		if(l-r<best){
				
			best=l-r;
		}
	}
	else{
		cout<<r-l<<endl;
		if(r-l<best){
				
			best=r-l;
		}
	}	
}

void present(int l){
	if(l==n){
		print();
		sum();
		return;
	}
	arr[l+1]=0;
	present(l+1);
	arr[l+1]=1;
	present(l+1);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	
	
	present(0);
	cout<<endl<<endl<<best;
}
