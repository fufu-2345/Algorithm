#include<iostream>
#include<vector>
using namespace std;

int n,w;
float val=0;
vector<vector<float>> arr;

void cal(float result[]){
	for(int i=0;i<n;i++){
		int most=0;
		int where;
		for(int j=0;j<n;j++){	
			if(arr[j][2]>most && result[j]==0){
				most=arr[j][2];
				where=j;
			}
		}
		
		if(w>arr[where][0]){
			result[where]=1;
			w-=arr[where][0];
			val+=arr[where][1];
		}
		else{
			result[where]=w/(arr[where][0]);
			val+=arr[where][1]*result[where];
			return;
		}
	}
}

int main(){
	cin>>n>>w;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back({a,0});
	}
	for(int i=0;i<n;i++){
		cin>>a;
		arr[i][1]=a;
		arr[i][2]=arr[i][1]/arr[i][0];
	}

	cout<<endl<<endl;
	
	float result[n]={0};
	cal(result);
	
	for(int i=0;i<n;i++){
		printf("%.2f ",result[i]);
	}
	printf("\n%.2f",val);
}
