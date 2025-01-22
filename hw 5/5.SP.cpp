#include <iostream>
#include <vector>
using namespace std;

int divide_and_conquer(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int length = high - low + 1;
    int part_size = length / 3;

    int mid1 = low + part_size - 1;
    int mid2 = low + 2 * part_size - 1;

    if (mid2 >= high) {
        mid2 = high - 1;
    }

    int count2_part1 = 0, count2_part2 = 0, count2_part3 = 0;
    for (int i = low; i <= mid1; ++i) {
        if (arr[i] == 2) count2_part1++;
    }
    for (int i = mid1 + 1; i <= mid2; ++i) {
        if (arr[i] == 2) count2_part2++;
    }
    for (int i = mid2 + 1; i <= high; ++i) {
        if (arr[i] == 2) count2_part3++;
    }

    if (count2_part1 != part_size) {
        return divide_and_conquer(arr, low, mid1);
    } else if (count2_part2 != part_size) {
        return divide_and_conquer(arr, mid1 + 1, mid2);
    } else {
        return divide_and_conquer(arr, mid2 + 1, high);
    }
}

int main() {
    vector<int> arr = {2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2};
    int odd_value = divide_and_conquer(arr, 0, arr.size() - 1);
    cout << "aaa¡: " << odd_value << endl;
    return 0;
}

