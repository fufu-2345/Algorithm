#include<iostream>
using namespace std;

int n;

float cal(float memo[],int now,int arr[]){
	if(now==0){
		return 0;
	}
	if(memo[now]!=0){
		return memo[now];
	}
	float temp=((cal(memo,now-1,arr)*(now-1))+arr[now-1])/now;
	memo[now]=temp;
	return temp;
}

int main(){
	cin>>n;
	float memo[n+1]={0};
	int arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	memo[1]=arr[0];
	cout<<endl<<endl<<cal(memo,n,arr);
	
	cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		cout<<memo[i]<<" ";
	}
}
