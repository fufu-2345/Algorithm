#include<iostream>
#include<vector>
using namespace std;

int m,n;
int count=0;
int dp[51][51]={0};

void cal(int n,int m){
	if(n==1 && m==1){
		count++;
		return;
	}
	
	if(dp[m][n]!=0){
        count++;
        return;
    }
    
	if(n-1>0){
		cal(n-1,m);
		dp[m][n]=1;
	}
	if(m-1>0){
		cal(n,m-1);
		dp[m][n]=1;
	}	
	
}

int main(){
	cin>>n>>m;
	
	cal(n,m);
	cout<<endl<<endl<<count;
}
