#include<iostream>
using namespace std;

int n,m;
int sum;
int a[1000],b[1000];

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void sort(int arr[]){
	for(int k=m/2;k>0;k/=2){
		for(int i=k;i<m;i++){
			for(int j=i;j>=k && arr[j]<arr[j-k];j-=k){
				swap(&arr[j],&arr[j-k]);
			}
		}
	}
}

void cal(){
	for(int i=0;i<m;i++){
		if(a[i]+b[m-i-1]<sum){
			cout<<"No"<<endl<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>a[j];
		}
		for(int j=0;j<m;j++){
			cin>>b[j];
		}
		cin>>sum;
		sort(a);
		sort(b);
		
		cout<<endl;
		cal();
	}
}
