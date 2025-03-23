#include<iostream>
#include<vector>
using namespace std;

int n,k;
int F(int N,int K,vector<vector<int>> memo){
	if(memo[N][K]!=-1){
		return memo[N][K];
	}
	if(K==0 || K==1 || N==K){
		return 1;
	}
	memo[N][K]=F(N-1,K,memo)+F(N-1,K-2,memo);
	return memo[N][K];
}


int main(){
	cin>>n>>k;
	vector<vector<int>> memo(n+1,vector<int>(n+1,-1));

	cout<<endl<<endl<<F(n,k,memo);
}
