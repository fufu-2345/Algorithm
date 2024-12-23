#include <iostream>
using namespace std;

void inperola(int arr[], int low, int high, int find)
{
    int posi = low + ((find - arr[low]) * (high - low) / (arr[high] - arr[low]));
    cout << posi << " ";

    if (arr[posi] == find)
    {
        return;
    }
    else if (posi >= low)
    {
        inperola(arr, posi + 1, high, find);
    }
    else
    {
        inperola(arr, low, posi - 1, find);
    }
}

int main()
{
    int n, find;
    cin >> n >> find;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;
    inperola(arr, low, high, find);
}