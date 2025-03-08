#include<vector>
#include<iostream>
using namespace std;

int n,m;
int sum=0;

void swap(int a,int b,vector<vector<int>>& arr){
	int temp=arr[a][0];
	int temp2=arr[a][1];
	int temp3=arr[a][2];
	
	arr[a][0]=arr[b][0];	
	arr[a][1]=arr[b][1];
	arr[a][2]=arr[b][2];
	
	arr[b][0]=temp;
	arr[b][1]=temp2;
	arr[b][2]=temp3;
}

void sort(vector<vector<int>>& arr){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<m;i++){
			for(int j=i;j>=k && arr[j][2]<arr[j-k][2];j-=k){
				swap(j,j-k,arr);
			}
		}
	}
}

void cal(vector<vector<int>> arr){
	int visit[m]={0};
	int count=0;
	for(int i=0;count<n && i<m;i++){
		if(visit[arr[i][0]]==0 || visit[arr[i][1]]==0){
			sum+=arr[i][2];
			//cout<<arr[i][2]<<endl;
			if(visit[arr[i][0]]==0){
				visit[arr[i][0]]=1;
				count++;
				cout<<arr[i][0]<<endl;
			}
			if(visit[arr[i][1]]==0){
				visit[arr[i][1]]=1;
				count++;
				cout<<arr[i][1]<<endl;
			}
		}
		
	}
}

int main(){
	cin>>n>>m;
	vector<vector<int>> arr;
	
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		arr.push_back({a,b,c-1});
	}
	
	sort(arr);
	cout<<endl<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cal(arr);
	cout<<sum;
}
