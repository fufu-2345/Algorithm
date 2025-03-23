#include<iostream>
#include<vector>
using namespace std;

int n,findd;
int minn=(1LL<<31)*-1;
vector<int> arr;

int cal() {
    vector<int> memo(findd+1,minn);
    memo[0]=0;

    for(int i=0;i<n;i++){
        for(int amount=findd;amount>=arr[i];amount--){
            if(memo[amount-arr[i]]!=minn){
                memo[amount]=max(memo[amount],memo[amount-arr[i]]+1);
            }
        }
        
        for(int j=0;j<=findd;j++){
        	cout<<memo[j]<<" ";
        }
        cout<<endl;
    }
    
    return memo[findd];
}

int main(){
	cin>>n;
	
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	cin>>findd;
	
	cout<<endl<<endl<<cal();
}
