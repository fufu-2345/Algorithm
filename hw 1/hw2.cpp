#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Size of array: ";
	cin >> n;
	int arr[100];
	if (n == 0)
	{
		n = 8;
		int arr[8] = {1, 2, 3, -99, 99, -99, 2, 1};
	}
	else
	{
		cout << "Enter the data: ";
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
	}

	int head = 0, tail = n;
	int max = -999, sum = 0;
	int bestHead, bestTail;

	////////////////////////////
	// greedy
	for (int i = 0; i < tail; i++)
	{
		if (arr[i] < 0)
		{
			head++;
		}
		else
		{
			break;
		}
	}
	for (int i = tail; i > head; i--)
	{
		if (arr[i - 1] < 0)
		{
			tail--;
		}
		else
		{
			break;
		}
	}
	if (head == tail)
	{
		int most = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > most)
			{
				most = arr[i];
			}
		}
		cout << most;
	}

	////////////////////////////

	else
	{
		int currentHead = head;
		int currentTail = head;
		int temp = 0;
		for (int i = head; i < tail; i++)
		{
			sum += arr[i];
			if (sum > max)
			{
				max = sum;
				bestHead = currentHead;
				bestTail = currentHead + temp + 1;
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

		cout << endl;
		for (int i = bestHead; i < bestTail; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl
			 << "last sum : " << max;
	}
}
