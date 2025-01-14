#include<iostream>
using namespace std;

int karasuba(int x,int y){
	
	int sign=1;
	if(x<0){
		sign*=-1;
		x*=-1;
	}
	if(y<0){
		sign*=-1;
		y*=-1;
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
	
	
	int k=(nx)/2;
	int a=x,b=x,c=y,d=y,z=1;;
	for(int i=0;i<k;i++){
		a/=10;
		c/=10;
		z*=10;
	}

	
	b-=a*z;
	d-=c*z;
	
	//cout<<a<<" "<<b<<endl;
	//cout<<c<<" "<<d<<endl;
	
	return sign*=(a*c*z*z)+(b*c*z)+(a*d*z)+(b*d);		
	
}

int main(){
	////    x    y
	////   342  231
	 
	int x,y;
	cin>>x>>y;
	
	
	if(x>y){
		cout<<karasuba(x,y);
	} 
	else {
		cout<<karasuba(y,x);
	}

}
