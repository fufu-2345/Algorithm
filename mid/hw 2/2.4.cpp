#include<iostream>
using namespace std;

int main(){
	int n,kep[100001]={0};
	cin>>n;
	
	int a[n],b[n],start=100000,stop=-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=a[i];j<b[i]+1;j++){
			if(a[i]<start){
				start=a[i];
			}
			if(b[i]>stop){
				stop=b[i];
			}
			kep[j]++;
		}	
	}
	
	int most=0,start2=0,end2=0;
	for(int i=start;i<stop;i++){
		if(kep[i]>most){
			most=kep[i];
			start2=i;
			while(kep[i+1]==kep[i]){
				i++;
			}
			end2=i;
		}
	}
	
	cout<<start2<<" "<<end2<<" "<<most;
}
