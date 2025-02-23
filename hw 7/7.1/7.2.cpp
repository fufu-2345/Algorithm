#include<iostream>
#include<vector>
using namespace std;

int n,count=0;
vector<vector<int>> arr;

void swap(int a,int b){
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

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>=k && (arr[j][0]<arr[j-k][0] || (arr[j][0]==arr[j-k][0] && arr[j][1]<arr[j-k][1]));j-=k){
				swap(j,j-k);
			}
		}
	}
}

void cal(){
	int time;
	vector<vector <int>> temp;
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
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr.push_back({a,b,i+1});
	}
	sort();
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i][2]<<": "<<arr[i][0]<<" "<<arr[i][1]<<endl;
	}
	
	cal();
	cout<<endl<<endl<<count;
}
