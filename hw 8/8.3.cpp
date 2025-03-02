#include <iostream>
#include <vector>
using namespace std;
int n,p,q;

bool dfs(int v,vector<vector<int>> graph,vector<bool> visit,vector<bool> miniVisit){
    visit[v]=true;
    miniVisit[v]=true;

    for(int i=0;i<graph[v].size();i++){
        if (visit[i]==false){
            if(dfs(i,graph,visit,miniVisit)==true){
                return true;
            }
        }
        else if (miniVisit[i]==true) {
            return true;
        }
    }

    miniVisit[v]=false;
    return false;
}

int hasCycle(vector<vector<int>> graph) {
    vector<bool> visit(n+1,false);
    vector<bool> miniVisit(n+1,false);

    for (int i = 1; i <= n; i++) {
        if (visit[i]==false) {
            if (dfs(i, graph, visit, miniVisit)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin>>n;
	
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n;i++){
        cin>>p;
        if(p==0){
        	cout<<"err";
			return 0;
		}
		while (true) {
            int q;
            cin>>q;
            if(q==0){
            	break;
			}
            graph[p].push_back(q);
        }
    }

    cout<<endl<<endl<<hasCycle(graph);
}

