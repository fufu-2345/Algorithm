#include<iostream>
#include<vector>
using namespace std;

int n;
int a,b;
vector<vector<int>> arr;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=0;i<n;i++){
			for(int j=i;j>=k && arr[j][2]>arr[j-k][2];j-=k){
				int temp=arr[j][0];
				int temp1=arr[j][1];
				int temp2=arr[j][2];
				
				arr[j][0]=arr[j-k][0];
				arr[j][1]=arr[j-k][1];
				arr[j][2]=arr[j-k][2];
				
				arr[j-k][0]=temp;
				arr[j-k][1]=temp1;
				arr[j-k][2]=temp2;
			}
		}
	}
}

void present(){
	for(int i=0;i<n;i++){
		if(a>=b){
			a+=arr[i][1];
			b+=arr[i][0];
		}
		else{
			a+=arr[i][0];
			b+=arr[i][1];
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a<b){
			swap(&a,&b);
		}
		arr.push_back({a,b,a-b});
	}
	
	sort();

	a=b=0;
	present();
	
	if(a>b){
		cout<<endl<<endl<<a-b;
	}
	else{
		cout<<endl<<endl<<b-a;
	}
}
