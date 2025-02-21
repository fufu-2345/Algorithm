#include<iostream>
using namespace std;

int main(){
	int a,b;
	int count=0;
	cin>>a>>b;
	
	while(a>1 || b>1){
		
		if(a==b){
			a=0;
			b=0;
		}
		else if(a>b){
			a-=b;
		}
		else{
			b-=a;
		}cout<<a<<" "<<b<<endl;
		
		count++;
	}
	
	if(a==1 && b==1){
		cout<<count+1;
	}
	else {
		cout<<count;
	}
}
