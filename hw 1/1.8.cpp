#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	

	int head = 0, tail = n;
	int max = -999, sum = 0;

	int currentHead = head;
	int temp = 0;
	for (int i = head; i < tail; i++)
	{
		sum += arr[i];
		if (sum > max)
		{
			max = sum;
		}
		if (sum > 0)
		{
			temp++;
		}
		else
		{
			temp = 0;
			sum = 0;
			currentHead = i + 1;
		}
	}

	cout<< max;
}
