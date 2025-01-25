#include<iostream>
using namespace std;

int karasuba(int x,int y,int* G){
	(*G)++;
	if(x<10 && y<10){
		return x*y;
	}

	int nx=0,ny=0,tempx=x,tempy=y;
	while(tempx>0 || tempy>0){
		if(tempx>0 && tempy>0){
			nx++;
			ny++;
			tempx/=10;
			tempy/=10;
		}
		else if(tempx==0){
			ny++;
			tempy/=10;
		}
		else if(tempy==0){
			nx++;
			tempx/=10;
		}
	}
	
	
	int k=(nx)/2,z=1;
	for(int i=0;i<k;i++){
		z*=10;
	}
	int a=x/z,b=x,c=y/z,d=y;
	b-=a*z;
	d-=c*z;
	
	int z1,z2,z3;
	z1=karasuba(a,c,G);
	z2=karasuba(a+b,c+d,G);
	z3=karasuba(b,d,G);

	
	return (z1*z*z)+z*(z2-z1-z3)+z3;	
	
	
}

int main(){
	////    x    y
	////   342  231
	int x,y,G=0;
	cin>>x>>y;
	
	int sign=1;
	if(x<0){
		sign*=-1;
		x*=-1;
	}
	if(y<0){
		sign*=-1;
		y*=-1;
	} 
	
	
	if(x>y){
		cout<<sign*karasuba(x,y,&G);
	} 
	else {
		cout<<sign*karasuba(y,x,&G);
	}
	cout<<endl<<endl<<G;
	
}
