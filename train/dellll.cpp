#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n,a,b,c;

void queen(int k,vector<int> arr){
	if(n==k){
		for(int i=0;i<n;i++){
			if(arr[i]==0){
				cout<<1<<" ";
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<2;i++){
			arr[k]=i;
			queen(k+1,arr);
		}
	}
}

int main(){
	cin>>n;
	vector<int> arr(n,0);
	
	queen(0,arr);
}
