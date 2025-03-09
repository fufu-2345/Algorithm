#include<iostream>
#include<vector>
#include<string>
using namespace std;

int best=(1LL<<31)-1;
int n,m;

void spread(int x,int y,vector<char> arr[],int sum,bool visit[][101]){
	if(arr[y][x]=='S'){
		int temp=sum-'S'+'0';
		if(temp<best){
			best=temp;
			visit[y][x]=false;
			return;
		}
	}

	if(y+1<n && ((arr[y+1][x] >= '0' && arr[y+1][x] <= '9') || arr[y+1][x] == 'S') && visit[y+1][x]==false){
		visit[y+1][x]=true;
		spread(x,y+1,arr,sum+(arr[y+1][x]-'0'),visit);
	}
	if(y-1>-1 && ((arr[y-1][x] >= '0' && arr[y-1][x] <= '9') || arr[y-1][x] == 'S') && visit[y-1][x]==false){
		visit[y-1][x]=true;
		spread(x,y-1,arr,sum+(arr[y-1][x]-'0'),visit);
	}
	if(x+1<m && ((arr[y][x+1] >= '0' && arr[y][x+1] <= '9') || arr[y][x+1] == 'S') && visit[y][x+1]==false){
		visit[y][x+1]=true;
		spread(x+1,y,arr,sum+(arr[y][x+1]-'0'),visit);
	}
	if(x-1>-1 && ((arr[y][x-1] >= '0' && arr[y][x-1] <= '9') || arr[y][x-1] == 'S') && visit[y][x-1]==false){
		visit[y][x-1]=true;
		spread(x-1,y,arr,sum+(arr[y][x-1]-'0'),visit);
	}
}

int main(){
	cin>>n>>m;
	vector<char> arr[n];
	bool visit[n][101];
	int x,y;
	char a;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a;
			arr[i].push_back(a);	
			if(a=='D'){
				x=j;
				y=i;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//cout<<arr[i][j]<<" ";
			visit[i][j]=false;
		}
		//cout<<endl;
	}
	
	spread(x,y,arr,0,visit);
	cout<<endl<<endl<<best;
}
