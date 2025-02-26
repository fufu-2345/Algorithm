#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> arr;
int most=0;
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
			for(int j=i;j>=k && (arr[j][1]<arr[j-k][1] );j-=k){
				swap(j,j-k);
			}
		}
	}
}

void cal() {
    int time;
	vector<int> temp;
	int visit[n] = {0};
	int size=0;
	
	for(int i=0;i<3;i++){
		temp.push_back(arr[i][1]);
		visit[i]=1;
	}
	count=3;
    
    for(int i=3;i<n;i++){
        for(int j=0;j<3;j++){
            if(visit[i]==0 && temp[j]<=arr[i][0]){
                visit[i]=1;
                temp[j]=arr[i][1]; 
                cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
                count++;
            }
        }
    }
}

/*
void cal(){
	int time;
	vector<vector <int>> temp;
	int visit[n] = {0};
	int size=0;
	
	for(int i=0;i<n;i++){
		temp.push_back(arr[i][1]);
		visit[i]=1;
	}
	count=n;
	
	for(int i=0;i<n;i++){
		for(int j=temp.size()-1;j>=0;j--){
			if(temp[j][1]<=time){
				size--;
			}
		}
		if(size()==3){
			continue;
		}
		
		for(int i=0;i<n;i++){
			for(int )
			if(visit[i]==0 && temp[i][0]==time){
				temp.push_back(arr[i]);
				count++;
				cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
				visit[i]=1;
				size++;
			}
		}
	}
}*/

int main(){
	cin>>n;
	int a,b;
	
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>most){
			most=a;
		}
		int c=b-a;
		arr.push_back({a,b,i+1,b-a});
	}
	sort();
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i][2]<<": "<<arr[i][0]<<" "<<arr[i][1]<<" | "<<arr[i][3]<<endl;
	}
	cout<<endl;
	cal();
	cout<<endl<<endl<<count;
}
