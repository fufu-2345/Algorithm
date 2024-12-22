#import <iostream>
using namespace std;

int main(){
	int n,find;
	cin>>n>>find;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	
	int kep[10001]={0};
	for(int i=0;i<n;i++){
		kep[arr[i]]=i;
	}
	
	int best=10001;
	for(int i=0;i<n;i++){
		int posi=arr[i]-find;
		
		if(posi>find){
			posi*=-1;
		}
		
		int temp=kep[posi];
		if(temp==0){
			continue;
		}
		else{
			int temp2=temp-i;
			if(temp2<0){
				temp2*=-1;
			}
			if(temp2<best){
				best=temp2;
			}
		}
	}
	cout<<best;
}
