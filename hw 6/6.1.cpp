#include<iostream>
using namespace std;

string arr="z";
int n;

int count[]={0};

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void print(){
	for(int i=1;i<n+1;i++){
		cout<<arr[i];
	}
	cout<<endl;
}

void permute(int l,int r){
	if(l==r){
		print();
		return;
	}
	for(int i=l;i<n+1;i++){
		swap(arr[l],arr[i]);
		permute(l+1,n);
		swap(arr[l],arr[i]);
	}
}

int main(){
	cin>>n;
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
	}
	
	for(int i=1;i<n+1;i++){
		count[arr[i]]++;
	}
	arr="z";
	for(int i='A';i<'Z'+1;i++){
		if(count[i]!=0){
			arr+=(char)i;
			
		}
	}
	cout<<endl;
	permute(1,n);
}
