#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int A[n], min = (1 << 31) - 1, max = -1 << 31;
	int S[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (A[i] > max)
		{
			max = A[i];
		}
		if (A[i] < min)
		{
			min = A[i];
		}
	}

	int D[max+1] = {0};
	for (int i = 0; i < n; i++)
	{
		D[A[i] - min]++;
	}

	for (int i = 1; i <= max; i++)
	{
		D[i] += D[i - 1];
	}

	for (int i = n; i >= 0; i--)
	{
		int j = A[i] - min;
		S[D[j] - 1] = A[i];
		D[j]--;
	}

	for (int i = 0; i < n; i++)
	{
		cout << S[i] << " ";
	}
}
