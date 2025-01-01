#include <iostream>
using namespace std;

int par(int l, int r, int arr[])
{
	int pi = arr[l], i = l, j = r;
	while (i < j)
	{
		while (arr[i] < pi)
		{
			i++;
		}
		while (arr[j] > pi)
		{
			j--;
		}
		if (i != j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	return j;
}

void sort(int l, int r, int arr[])
{
	if (r > l)
	{
		int s = par(l, r, arr);
		sort(l, s - 1, arr);
		sort(s + 1, r, arr);
	}
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	sort(0, n - 1, arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
