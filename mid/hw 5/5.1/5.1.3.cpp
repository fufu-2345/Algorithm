#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>merge(vector<vector<int>> l,vector<vector<int>> r,int* count){
	int n=l.size(),n2=r.size();
	vector<vector<int>> result;
	
    int y = -(1<<31);
    for (int i = 0; i < n2; i++){
        if(r[i][1] > y){
            y = r[i][1];
        }
    }
    
    for (int i = 0; i < n; i++){
        if (l[i][1] > y){
            result.push_back(l[i]);
        }
    }

	for (int i=0;i<n2;i++){
        result.push_back(r[i]);
    }
	
	(*count)++;
	return result;
}


vector<vector<int>> maxima(vector<vector<int>> v,int l,int r,int* count){
	(*count)++;
	if(l==r){
		return vector<vector<int>>{v[l]};
	}
	
	int m=(l+r-1)/2;

	vector<vector<int>> vl=maxima(v,l,m,count);
	vector<vector<int>> vr=maxima(v,m+1,r,count);
	
	
	return merge(vl,vr,count);
}


int main(){
	//  9        7 2 3 1 9 3 4 5 1 4 6 9 2 6 5 7 8 6 
	int n,count=-1;
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
    for (int i=0;i<100;i++) {	
    	if(arr[i]!=0){
        	v[kep]=tempv[arr[i]-1]; 
        	kep++;
		}
    }
    
	tempv.clear();
    tempv.shrink_to_fit();   
	
	
	vector<vector<int>> result=maxima(v,0,n-1,&count);
	n=result.size();
	
	for(int i=0;i<n;i++){
		cout<<"{"<<result[i][0]<<","<<result[i][1]<<"} ";
	}
	cout<<endl<<"count: "<<count;
	
}
