#include<iostream>
using namespace std;

int fac(int now,int memo[]){
	if(memo[now]==0){
		memo[now]=fac(now-1,memo)*now;
	}
	return memo[now];
}

int main(){
	int n,k;
	cin>>n>>k;
	int memo[n+1]={1};
	
	cout<<endl<<endl<<fac(n,memo)/ (fac(n-k,memo)*fac(k,memo));
}
