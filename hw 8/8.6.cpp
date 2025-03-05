#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int best=(1LL<<31)-1;
int minn=(1LL<<31)-1;

void check(int x,vector<int> arr[]){
	vector<bool> visit(n,false);
	queue<int> queue;
	queue.push(x);
	visit[x]=true;
	
	int k=1,count=0;
	while(!queue.empty()){
		int current=queue.front();
		//cout<<current<<" ";
		queue.pop();
		
		for(int i=0;i<arr[current].size();i++){
			if(arr[current][i]==1 && !visit[i]){
				count+=k;
				queue.push(i);
				visit[i]=true;
			}
		}
		k++;
	}
	
	//cout<<x<<" "<<count<<endl;
	if(count<minn || (count==minn && x<best)){
		best=x;
		minn=count;
	}
	
}

int main(){
	cin>>n>>m;
	
	vector<int> arr[n+1];
	int a,b;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<n+1;j++){
			arr[i].push_back(0);
		}
	}
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
    
    /*for(int i=1;i<=n;i++){
		for(int j=1;j<n+1;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
    for(int i=1;i<=n;i++){
    	check(i,arr);
	}
	
	cout<<endl<<endl<<best;
    
}
