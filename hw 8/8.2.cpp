#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;

void check(int x,vector<int> arr[]){
	vector<bool> visit(n,false);
	queue<int> queue;
	queue.push(x);
	visit[x]=true;
	
	while(!queue.empty()){
		int current=queue.front();
		queue.pop();
		//cout<<current<<" ";
		
		for(int i=0;i<arr[current].size();i++){
			int temp=arr[current][i];
			if(!visit[temp]){
				queue.push(temp);
				visit[temp]=true;
			}
		}
	}
	
	int c=0;
	for(int i=1;i<=n;i++){
		if(visit[i]==false){
			cout<<i<<" ";
			c=1;
		}
	}
	if(c==0){
		cout<<0;
	}
}

int main(){
	cin>>n;
	
	vector<int> arr[n+1];
	int a,b;
    
    for(int i=1;i<=n;i++){
		cin>>a;
		while(true){
			cin>>b;	
			if(b==0){
				break;
			}
			arr[a].push_back(b);	
		} 
    }
    
    cin>>a;
    cout<<endl<<endl;
    
    for(int i=1;i<=a;i++){
    	cin>>b;
    	check(b,arr);
    	cout<<endl;
	}
    
}
