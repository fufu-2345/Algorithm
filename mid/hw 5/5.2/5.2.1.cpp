#include<iostream>
using namespace std;

int Max_Subarray_Sum(int A[], int n) {
    if (n == 1) {
        return A[0];
    }

    int m = n / 2;
    int Lmss = Max_Subarray_Sum(A, m);
    int Rmss = Max_Subarray_Sum(A + m, n - m);
    int lsum = -1000, rsum = -1000, sum = 0;
    


    for (int i = m; i < n; i++) {
        sum += A[i];
        rsum = max(rsum, sum);
        //cout<<rsum<<" "<<sum<<endl;
    }
	
	cout<<endl;
    sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        sum += A[i];
        lsum = max(lsum, sum);
        //cout<<lsum<<" "<<sum<<endl;
    }
    
    cout<<endl<<"array: ";
    for(int i=0;i<n;i++){
    	cout<<A[i]<<" ";
	}
	cout<<endl<<"return: "<<max(max(Lmss, Rmss), lsum + rsum);

    return max(max(Lmss, Rmss), lsum + rsum);
}


int main(){
	
	//  8      16 -25 2 -54 36 9 -12 66
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	
	cout<<endl<<endl<<endl<<Max_Subarray_Sum(arr,n);
}
