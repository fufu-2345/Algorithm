#include<iostream>
using namespace std;

int arr[5];
int n;

void printt(int l){
	for(int i=1;i<=l;i++){
		cout<<arr[i]<<" ";
	}
	if(l>0){
		cout<<endl;
	}
}

void subset(int l){
	printt(l);
	int j;
	if(l==0){
		j=1;
	}
	else{
		j=arr[l]+1;
	}
	for(int i=j;i<=n;i++){
		arr[l+1]=i;
		subset(l+1);
	}
}

int main(){
	cin>>n;
	subset(0);
}
