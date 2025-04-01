#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int best=(1LL<<31)-1;
int minn=(1LL<<31)-1;

void check(int start,vector<int> arr[]){
	vector<bool> visit(n+1,false);
	vector<int> parent(n+1,-1);
	queue<int> queue;
	queue.push(start);
	visit[start]=true;
	
	//int k=1,count=0;
	while(!queue.empty()){
		int current=queue.front();
		cout<<current<<" ";
		queue.pop();
		
		for(int i=0;i<arr[current].size();i++){
			int neighbor = arr[current][i];
            if (!visit[neighbor]) {
                //count += k;
                queue.push(neighbor);
                visit[neighbor] = true;
            }
        }
        //k++;
	}

	/*if(count<minn || (count==minn && start<best)){
		best=start;
		minn=count;
	}*/
	cout<<endl;
}

int main(){
	cin>>n>>m;
	
	vector<int> arr[n+1];
	int a,b;
	
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<n+1;j++){
			arr[i].push_back(0);
		}
	}*/
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
    /*
    for(int i=1;i<=n;i++){
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<endl<<endl;
    for(int i=1;i<=n;i++){
    	check(i,arr);
	}
	
	cout<<endl<<endl<<best;
    
}
