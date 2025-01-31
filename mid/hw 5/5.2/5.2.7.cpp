#include<iostream>
using namespace std;

long long Multiply(int a,int b){
	if(a<10){
		return a*b;
	}
	int a1=a,b1=1,a2=a,b2=b;
	while(a1>10){
		a1/=10;
		b1++;
	}
	
	int z=1;
	for(int i=0;i<b1/2;i++){
		z*=10;
	}
	
	a1=a/z;
	b1=b/z;
	a2-=a1*z;
	b2-=b1*z;
	
	long long A=Multiply(a1,b1);
	long long B=Multiply(a2,b2);
	long long C=Multiply(a1+a2,b1+b2);
	
	
	cout<<A<<" "<<B<<" "<<C<<endl;
	
	return A*z*z+(C-A-B)*z+B;
}

int main(){
	//    4568 3275
	int a,b;
	cin>>a>>b;
	
	cout<<Multiply(a,b);
}
