#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int n;
vector<vector<float>> arr;
int count=0;

void swap(int a,int b){
	float temp=arr[a][0];
	float temp2=arr[a][1];
	
	arr[a][0]=arr[b][0];
	arr[a][1]=arr[b][1];
	
	arr[b][0]=temp;
	arr[b][1]=temp2;
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>=k && arr[j][0]<arr[j-k][0];j-=k){
				swap(j,j-k);
			}
		}
	}
}

void cal(){
	float time;
	vector<vector <float>> temp;
	for(int i=0;i<n;i++){
		time=arr[i][0];
		temp.push_back(arr[i]);
		for(int j=temp.size()-1;j>=0;j--){
			if(temp[j][1]<=time){
				temp.erase(temp.begin()+j);
			}
		}
		if(temp.size()>count){
			count=temp.size();
		}
	}
}

int main(){
	cin>>n;
	float a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,b});
	}
	sort();
	cal();
	cout<<endl<<endl<<count;
}
