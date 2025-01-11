#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int size = 10000;
	int a[n], b[n], arr[size] = {0};
	int inter[n * 2];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		arr[a[i]]++;
		inter[i] = a[i];
	}

	int kep = n;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		if (arr[b[i]] == 0)
		{
			inter[kep] = b[i];
			kep++;
		}
		arr[b[i]]++;
	}

	//////////////// print 1
	for (int i = 0; i < n; i++)
	{
		if (arr[a[i]] > 1)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
	/////////////////

	//////////////// print 2
	for (int i = 0; i < kep; i++)
	{
		cout << inter[i] << " ";
	}
	/////////////////
}
