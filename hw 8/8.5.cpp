#include<iostream>
#include<vector>
using namespace std;

int x,y,count=0;
char temp;

void print(vector<vector<char>>& arr){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
													//*******************************
void spread(int currentX,int currentY,vector<vector<char>>& arr,vector<vector<bool>>& visit){	
	char val=arr[currentX][currentY];
	visit[currentX][currentY]=true;
	count++;
	
	if(currentX-1>=0 && visit[currentX-1][currentY]==false && arr[currentX-1][currentY]==val){			
		spread(currentX-1,currentY,arr,visit);
		//count++;
	}
	if(currentX+1<x && visit[currentX+1][currentY]==false && arr[currentX+1][currentY]==val){
		spread(currentX+1,currentY,arr,visit);
		//count++;
	}
	if(currentY-1>=0 && visit[currentX][currentY-1]==false && arr[currentX][currentY-1]==val){
		spread(currentX,currentY-1,arr,visit);
		//count++;
	}
	if(currentY+1<x && visit[currentX][currentY+1]==false && arr[currentX][currentY+1]==val){
		spread(currentX,currentY+1,arr,visit);
		//count++;
	}
}

int main(){
	cin>>x>>y;
	vector<vector<char>> arr(y);
	vector<vector<bool>> visit(y,vector<bool> (x,false));
	
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			cin>>temp;
			arr[i].push_back(temp);
		}
	}
	
	cout<<endl<<endl;
	print(arr);

	int a,b;
	cin>>a>>b;
	spread(a-1,b-1,arr,visit);
	
	cout<<endl<<endl<<count;
}
