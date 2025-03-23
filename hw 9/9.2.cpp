#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int count=0;
vector<int> arr[101];

int cal(int start){
	vector<bool> visit(101,false);
	queue<int> que;
	que.push(start);
	visit[start]=true;
	
	int k=1,sum=0;
	while(!que.empty()){
		int current=que.front();
		//cout<<que.front()<<" ";
		que.pop();
		for(int i=0;i<arr[current].size();i++){
			int temp=arr[current][i];
			if(visit[temp]==false){
				count++;
				sum+=k;
				que.push(temp);
				visit[temp]=true;
			}
		}
		k++;
	}
	return sum;
}

int main(){
	int a=-1,b=-1;
	while(true){
		cin>>a>>b;
		if(a==0 && b==0){
			break;
		}
		arr[a].push_back(b);
	}
	
	float result=0;
	for(int i=1;i<101;i++){
		if(arr[i].size()==0){
			continue;
		}
		result+=cal(i);
	}
	printf("\n\n%.4f",result/count);
}
