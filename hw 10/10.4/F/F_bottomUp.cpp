#include<iostream>
#include<vector>
using namespace std;

int n,k;
int F(int N,int K,vector<vector<int>> memo){
	for(int i=1;i<=N;i++){
		for(int j=2;j<=K;j++){
			if(i!=j && memo[i][j]==0){
				memo[i][j]=memo[i-1][j]+memo[i-1][j-2];
			}
		}
	}
	
	return memo[N][K];
}


int main(){
	cin>>n>>k;
	vector<vector<int>> memo(n+1,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j==0 || j==1 || i==j){
				memo[i][j]=1;
			}
		}
	}
	cout<<endl<<endl<<F(n,k,memo);
}
