#include<iostream>
using namespace std;

int par(int arr[],int l,int r){
	int n=r-l;
	int pi=(r+l)/2;
	int i=l,j=r;
	
	int temp=arr[i];
	arr[i]=arr[pi];
	arr[pi]=temp;
	
	pi=arr[r];
	
	while(i<j){
		while(arr[i]<pi){
			i++;
		}
		while(arr[j]>pi){
			j--;
		}
		
		if(i!=j){
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	return i;
}

int quickSelect(int arr[],int l,int r,int k){
	
	if(l==r){
		return arr[l];
	}
	
	int p=par(arr,l,r);
	if(p==k-1){
		return arr[p];
	}
	else if(arr[p]>k){
		return quickSelect(arr,l,p-1,k);
	}
	else{
		return quickSelect(arr,p+1,r,k);
	}
}



int main(){
	int arr[]={1,5,10,4,8,2,6,9,20};
	int k=4,n=sizeof(arr)/sizeof(arr[0]);
	
	
	cout<<quickSelect(arr,0,n-1,k)<<endl;
}
