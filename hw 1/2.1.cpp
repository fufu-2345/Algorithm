#include<iostream>
using namespace std;

int main(){
	bool check=true;
	int n,find;
	cin>>n>>find;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	
	int low=0;
	int high=n-1;
	while(find>=arr[low] && find<=arr[high]){
		int posi=low+   (   (   (find-arr[low])*(high-low)   ) /  (arr[high] - arr[low])    );
		cout<<posi<<" ";
		if(arr[posi]==find){
			break;
		}
		if(posi>=low){
			low=posi+1;
		}
		else{
			high=posi-1;
		}
	}
}
