#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>merge(vector<vector<int>> l,vector<vector<int>> r){
	int n=l.size(),n2=r.size();
	vector<vector<int>> result;
	
	for(int i=0;i<n;i++){
		bool check=true;
		for(int j=0;j<n2;j++){
			if(l[i][1]<r[j][1]){
				check=false;
				break;
			}
		}
		if(check==true){
			result.push_back(l[i]);
		}
	}
	
	for (int i = 0; i < n2; i++) {
        result.push_back(r[i]);
    }
	
	return result;
}

vector<vector<int>> maxima(vector<vector<int>> v,int l,int r){
	if(l==r){
		return vector<vector<int>>{v[l]};
	}
	
	int m=(l+r-1)/2;

	vector<vector<int>> vl=maxima(v,l,m);
	vector<vector<int>> vr=maxima(v,m+1,r);
	
		
	return merge(vl,vr);
}


int main(){
	//  9        7 2 3 1 9 3 4 5 1 4 6 9 2 6 5 7 8 6 
	int n;
	cin>>n;
	
	vector<vector<int>> tempv;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		tempv.push_back({x,y});
	}
	
	
	int arr[100]={0};
	for(int i=0;i<n;i++){
		arr[tempv[i][0]]=i+1;
	}

	vector<vector<int>> v(n); 
	
	int kep=0;
    for (int i = 0; i < 100; i++) {	
    	if(arr[i]!=0){
        	v[kep] = tempv[arr[i]-1]; 
        	kep++;
		}
    }
    
	tempv.clear();
    tempv.shrink_to_fit();   
	
	
	vector<vector<int>> result=maxima(v,0,n-1);
	n=result.size();
	
	for(int i=0;i<n;i++){
		cout<<"{"<<result[i][0]<<","<<result[i][1]<<"} ";
	}
	
}
