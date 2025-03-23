#include<iostream>
#include<vector>
using namespace std;

int n;

int G(int i,vector<int> memo){
	if(memo[i]!=-1){
		return memo[i];
	}
	for(int j=3;j<=i;j++){
		memo[j]=G(j-1,memo)+G(j-2,memo)-G(j-3,memo);
	}
	
	return memo[i];
}

int main(){
	cin>>n;
	vector<int> memo(n+1,-1);
	memo[0]=0;
	memo[1]=1;
	memo[2]=1;
	cout<<endl<<endl<<G(n,memo);
}
