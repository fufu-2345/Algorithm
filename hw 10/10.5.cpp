#include<iostream>
using namespace std;

int fx(int now,int memo[]){
	if(memo[now]!=0){
		return memo[now];
	}
	return (fx(now-1,memo)*3)+fx(now-2,memo);
}

int main(){
	int n,count=0;
	cin>>n;
	int memo[n+1]={1,1};
	cout<<endl<<endl<<fx(n-1,memo);
}
