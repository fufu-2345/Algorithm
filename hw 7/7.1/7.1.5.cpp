#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> arr;
int n;

void swap(int a,int b){
	int temp=arr[a][0];
	int temp2=arr[a][1];
	
	arr[a][0]=arr[b][0];
	arr[a][1]=arr[b][1];
	
	arr[b][0]=temp;
	arr[b][1]=temp2;
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>k&&   (  ( arr[j][0]==arr[j-k][0] && arr[j][1]<arr[j-k][1])     || arr[j][0]<arr[j-k][0])    ;j-=k){
				swap(j,j-k);
			}
		}
	}
}

void merge(){
	int max=1;
	int now=0;
	int best;
	while(now<n){
		int most=0;
		
		while(arr[now][0]<=max){
			if(arr[now][1]>most){
				best=now;
				most=arr[now][1];
			}
			now++;
			if(now==n){
				break;
			}
		}
		max=most;
		cout<<arr[best][0]<<" "<<arr[best][1]<<endl;
	}
}

int main(){
	int a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,b});
	}
	sort();
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
	}
	cout<<endl<<endl;
	merge();
}

