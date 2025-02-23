#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> arr;
int count=0;

void swap(int a,int b){
	int temp=arr[a][0];
	int temp2=arr[a][1];
	int temp3=arr[a][2];
	int temp4=arr[a][3];
	
	arr[a][0]=arr[b][0];
	arr[a][1]=arr[b][1];
	arr[a][2]=arr[b][2];
	arr[a][3]=arr[b][3];
	
	arr[b][0]=temp;
	arr[b][1]=temp2;
	arr[b][2]=temp3;
	arr[b][3]=temp4;
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>=k && (arr[j][3]>arr[j-k][3] || (arr[j][3]==arr[j-k][3] && arr[j][0]<arr[j-k][0]));j-=k){
				swap(j,j-k);
			}
		}
	}
}

void cal(){
	vector<vector<int>> temp;
	for(int i=0;i<n;i++){
		int time=
		temp.push_back(arr[i]);
		for(int j=0;j<temp.size())
	}
}

int main(){
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int c=b-a;
		arr.push_back({a,b,i+1,b-a});
	}
	sort();
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i][2]<<": "<<arr[i][0]<<" "<<arr[i][1]<<" | "<<arr[i][3]<<endl;
	}
	cal();
	cout<<endl<<endl<<count;
}
