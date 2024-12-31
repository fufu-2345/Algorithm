#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<endl<<endl;
	
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;		
			}
		}
		
		if(i!=min){
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;	
		}
	}
	
	int kep=0;
	string re="";
	for(int i=0;i<n;i++){
		string temp="";
		while(arr[i]!=0){
			temp=char(    (arr[i]%10)   +'0') +temp;
			arr[i]/=10;
			kep++;
		}
		re+=temp;
	}
	cout<<re<<endl;
	
	int memo[10]={0},most=-1;
	string last="";
	for(int i=0;i<kep;i++){
		int temp=re[i],count=1;
		while(i+1<kep && re[i+1]==temp){
			count++;
			i++;
		}
		if(count>memo[temp-'0']){
			memo[temp-'0']=count;
		}
		if(count>most){
			most=count;
		}
		last+=temp;
	}
	
	
	for(int i=0;i<10;i++){
		if(memo[i]==most){
			cout<<i<<" ";
		}
	}
	
	cout<<endl<<last;
	
	
	
}
