#include<iostream>
using namespace std;

unsigned long long n;

unsigned long long fibo(unsigned long long memo[],unsigned long long now){
	if(memo[now]!=0){
		return memo[now];
	}
	unsigned long long temp=fibo(memo,now-1)+fibo(memo,now-2);
	memo[now]=temp;
	return temp;
}

int main(){
	cin>>n;
	unsigned long long memo[n+1]={1};
	memo[1]=1;
	
	cout<<endl<<endl<<fibo(memo,n);
}
