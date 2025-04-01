#include<iostream>
using namespace std;

int M[100][100];

int max(int x, int y)
{  return x > y? x:y;
}

int knapsack(int Wt, int w[], int v[], int n) {
    if (n == 0 || Wt == 0)
        return 0;

    if (M[n][Wt] != -1)
        return M[n][Wt];

    if (w[n - 1] > Wt)
        return M[n][Wt] = knapsack(Wt, w, v, n - 1);

    return M[n][Wt] = max(v[n-1] + knapsack(Wt-w[n-1], w, v, n-1),
                          knapsack(Wt, w, v, n-1));
}

int main()
{ int val[] = {10, 40, 30, 50};
  int w[] = {5, 4, 6, 3};
  int Wt = 5;
  int N = 4;

  for(int i=0;i<=N;i++)
    for(int j=0; j<=Wt; j++)
      {  if(j == 0 || i == 0)
             M[i][j] = 0;
         else
             M[i][j] = -1;
      }

cout<<endl<<endl;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=Wt;j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
  printf("%d", knapsack (Wt, w, val, N));
	
	cout<<endl<<endl;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=Wt;j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
}
