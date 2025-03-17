#include<iostream>
#include<vector>
using namespace std;

vector<int> coins;
int n,w;

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;	
}

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=k;i<n;i++){
			for(int j=i;j>=k && coins[j]<coins[j-k];j-=k){
				swap(coins[j],coins[j-k]);
			}
		}
	}
}

void cal(){
	vector<int> memo(w+1,(1LL<<31)-1);
	memo[0]=0;
	for(int money=0;money<=w;money++){
		for(int i=0;i<n;i++){
			int coin=coins[i];
			if(coin<=money){
				int temp=memo[money-coin]+1;
				if(temp<memo[money]){
					memo[money]=temp;
				}
			}
		}
	}
	for(int money=0;money<=w;money++){
		cout<< memo[money]<<" ";
	}
	cout<<endl<< memo[w];
}


int main(){
	int a;
	cin>>n>>w;
	
	for(int i=0;i<n;i++){
		cin>>a;
		coins.push_back(a);
	}
	
	sort();
	for(int i=0;i<n;i++){
		cout<<coins[i]<<" ";
	}
	cout<<endl;
	cal();
}
