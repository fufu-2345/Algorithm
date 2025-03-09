#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int best=(1LL<<31)-1;
int minn=(1LL<<31)-1;
vector<int> noo;

void cal(int x,vector<pair<int,int>> arr[]){
	vector<bool> visit(n+1,false);
	queue<pair<int,int>> queue;
	queue.push({x,0});
	visit[x]=true;
	
	int sum=0;
	while(!queue.empty()){
		int current=queue.front().first;
		int temp=queue.front().second;
		bool check=true;
    	for(int j=0;j<m;j++){
    		if(noo[j]==current){
    			check=false;
			}
		}
		if(check==true){
			sum+=temp;
		}
		
		queue.pop();
		
		
		for(int i=0;i<arr[current].size();i++){
			int neighbor=arr[current][i].first;
			if(!visit[neighbor]){
				queue.push({neighbor,temp+arr[current][i].second});
				visit[neighbor]=true;
			}
		}
	}
	
	cout<<sum<<endl;
	if(sum<minn || (sum==minn && x<best)){
		best=x;
		minn=sum;
	}
	
}

int main(){
	cin>>m>>n;
	vector<pair<int,int>> arr[n+1];
	int a,b,c;
	
	for(int i=0;i<m;i++){
		cin>>a;
		noo.push_back(a);
	}
	
	
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		arr[a].push_back({b,c});
		arr[b].push_back({a,c});
	}
    
    cout<<endl;
    for(int i=1;i<=n;i++){
    	bool check=true;
    	for(int j=0;j<m;j++){
    		if(noo[j]==i){
    			check=false;
			}
		}
		if(check==true){
			cal(i,arr);
		}	
	}
	
	cout<<endl<<endl<<best;
    
}
