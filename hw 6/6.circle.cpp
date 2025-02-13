#include <iostream>
using namespace std;

int n;
int count=0;
int arr[1000];
int used[21][21]={};

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


void permute(int l){
	if(l==n){
		/*for(int i=0;i<count;i++){
			int now=0;
			for(int j=0;j<n;i++){
				if(arr[j])
			}
		}*/
		
		for(int i=0;i<n-1;i++){
			int temp=arr[i]+arr[i+1];
			//cout<<arr[i]<<" "<<arr[i+1]<<endl;
			for(int i=2;i<temp;i++){
				if(temp%i==0){
					return;
				}
			}
		}
		int temp=arr[n-1]+arr[0];
		//cout<<arr[n-1]<<" "<<arr[0]<<endl;
		for(int i=2;i<temp;i++){
			if(temp%i==0){
				return;
			}
		}
		//cout<<"A"<<endl<<endl<<endl;
		
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl<<endl;
		count++;
		return;
	}
	for(int i=l;i<n;i++){
		//swap(arr[l],arr[i]);
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
