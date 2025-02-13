#include <iostream>
using namespace std;

int n;
int count=0;
int arr[5]={0};
int used[21][21]={};

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


void permute(int l){
	if(l==n){
		int diff=0;
		while(arr[diff]!=1){
			diff++;
		}
		int sorted[n];
		if(diff>0){
			for(int i=0;i<n;i++){
				sorted[i]=arr[diff];
				if(diff==n-1){
					diff=0;
				}
				else{
					diff++;
				}
			}
		}
		
		if(count>0){
			for(int i=0;i<count;i++){
				bool check=true;
				for(int j=0;j<n;j++){
					if(sorted[j]!=used[i][j]){
						check=false;
						break;
					}
				}
				if(check){
					return;
				}
			}
		}
		
		for(int i=0;i<n-1;i++){
			int temp=sorted[i]+sorted[i+1];
			for(int i=2;i<temp;i++){
				if(temp%i==0){
					return;
				}
			}
		}
		int temp=sorted[n-1]+sorted[0];
		for(int i=2;i<temp;i++){
			if(temp%i==0){
				return;
			}
		}
		
		for(int i=0;i<n;i++){
			used[count][i]=sorted[i];
			cout<<sorted[i]<<" ";
		}
		cout<<": "<<diff<<endl;
		count++;
		return;
	}
	for(int i=l;i<n;i++){
		swap(arr[l],arr[i]);
		permute(l+1);
		swap(arr[l],arr[i]);
	}
	
	
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	permute(0);
	cout<<endl<<count;
}
