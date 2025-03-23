#include<iostream>
#include <vector>
#include <queue>
using namespace std;

//  https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

int n,m;
int sum=0;
int start;

int cal(vector<vector<int>> edges) {
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0]-1;
        int v=edges[i][1]-1;
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pair<int,int>,   vector<pair<int,int>>,   greater<pair<int,int>>> pq;
    vector<bool> visited(n, false);

    pq.push({0,start});

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();

        int wt=p.first;
        int u=p.second;

        if(visited[u])continue;

        sum+=wt;
        visited[u]=true;

        for(auto v:adj[u]){
            if(!visited[v.first]){
                pq.push({v.second,v.first});
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
		arr.push_back({a,b,c});
	}
	cin>>start;
	cal(arr);
	cout<<endl<<endl<<sum;
}
