#include<iostream>
using namespace std;

int swap(int* x,int* y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int par(int arr[],int l,int r){
	int i=l,j=r,pivot=arr[l];
	while(i<j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		swap(arr[i],arr[j]);
	}
	return j;
}

void sort(int arr[],int l,int r){
	if(l<r){
		int p=par(arr,l,r);
	
		sort(arr,l,p-1);
		sort(arr,p+1,r);
	}
}

int bisearch(int arr[],int l,int r,int find){
    int closest=-999;

    while(l<=r){
        int m=l+(r-l)/ 2;
        if(arr[m] == find) {
            return m;
        }

        if(closest == -999 || abs(arr[m] - find) < abs(arr[closest] - find)) {
            closest = m;
        }
        

        if(find>arr[m]){
            l=m+1;
        } else {
            r=m-1;
        }
    }

    return closest;
}


int main(){
	/*  10,12,15,17,18,20,25
	int n,k,m;
	cin<<n<<k<<m;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin<<arr[n];
	}*/
	
	int arr[]={18, 15, 12, 25, 17, 20, 10};
	int k=2,M=16,n=(sizeof(arr)/sizeof(arr[0]));
	
	
	sort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
	int where;
	cout<<endl;
	if(M<arr[0]){
		where=0;
	}
	else if(M>arr[n-1]){
		where=n-1;
	}
	else {
		where=bisearch(arr,0,n-1,M);
	}
	
	cout<<where;
	
	
}
