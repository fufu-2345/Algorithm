#include<iostream>
using namespace std;

int arr[1000];
int book[1000];
int n;
int k;
int done=0;

void subset(int l,int count){
	if(done==1){
		return;
	}
	if(l==n){
		if(count<3){
			return;
		}
		int temp[3]={0};
		int kep=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(arr[i+1]==1){
				sum+=book[i];
				if(sum>k){
					return;
				}
				temp[kep]=book[i];
				kep++;
			}
		}	

		if(sum==k){	
			for(int i=0;i<3;i++){
				int low=600;
				int where=0;
				for(int j=0;j<3;j++){	
					if(temp[j]<low){
						low=temp[j];
						where=j;
					}
				}
				cout<<low<<" "<<endl;
				temp[where]=600;
			}
			done=1;
		}
		return;
	}	
	
	arr[l+1]=0;
	subset(l+1,count);
	if(count<=2){
		arr[l+1]=1;
		subset(l+1,count+1);
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>book[i];
	}
	cout<<endl<<endl;
	subset(0,0);
	if(done==0){
		cout<<0<<endl<<0<<endl<<0<<endl;
	}
}
