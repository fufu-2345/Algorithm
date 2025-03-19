#include<iostream>
#include<vector>
using namespace std;

int n;
int a,b;

class present{
	public:
	int more;
	int less;
	int diff;
	
	present(int m,int l,int d):more(m),less(l),diff(d){}

};

vector<present> presents;

void sort(){
	for(int k=n/2;k>0;k/=2){
		for(int i=0;i<n;i++){
			for(int j=i;j>=k &&     presents[j].diff>presents[j-k].diff       ;j-=k){
				present temp=presents[j];
                presents[j]=presents[j-k];
                presents[j-k]=temp;
			}
		}
	}
}

void cal(){
	for(int i=0;i<n;i++){
		if(a>=b){
			a+=presents[i].less;
			b+=presents[i].more;
		}
		else{
			a+=presents[i].more;
			b+=presents[i].less;
		}
		cout<<a<<" "<<b<<endl;
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a<b){
			int temp=a;
			a=b;
			b=temp;
		}
		presents.push_back(present(a,b,a-b));
	}
	
	sort();

	a=b=0;
	cout<<endl<<endl;
	cal();
	
	if(a>b){
		cout<<endl<<endl<<a-b;
	}
	else{
		cout<<endl<<endl<<b-a;
	}
}
