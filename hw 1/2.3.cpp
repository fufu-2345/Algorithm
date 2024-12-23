#include<iostream>
#include <cmath>
using namespace std;

int swap(int* x,int* y){
	int temp=*x;
	*x=*y;
	*y=temp;	
}

int main(){
	
	int n;
	cin>>n;
	
	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int kep[(n/2)+1]={1},k=0,now=1;
	
	for(int i=0;now<n;i++,k++){
		kep[i]=now;
		now=pow(4,i)+(3*pow(2,i))+1;
	}
	
	//for(int round=0;round<k;round++){
		for(int i=0;i<n/2;i++){
			cout<<arr[kep[k-1]+i]<<" "<<arr[i]<<" "<<endl;
			if(arr[kep[k-1]+i]<arr[i]){
				swap(&arr[kep[k-1]+i],&arr[i]);
			}
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	//}
	
	
	
	
	
	
	
}
