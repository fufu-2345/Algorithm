#include<iostream>
using namespace std;

int n;
int arr[1000];
int a=0;
int b=0;

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

void present(){
	for(int i=0;i<n;i++){
		if(a<=b){
			a+=arr[i];
		}
		else{
			b+=arr[i];
		}
	}
}

int main(){
	cin>>n;
	n*=2;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort();
	present();

	if(a>b){
		cout<<a-b;
	}
	else{
		cout<<b-a;
	}
}
