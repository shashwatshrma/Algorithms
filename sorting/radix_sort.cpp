#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printarr(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void radix_sort(vector<int> &arr)
{
    int n = arr.size();
    int d = ceil(log10(max_element(arr, n)));
    for (int exp = 1, i = 0; i < d; i++, exp *= 10)
    {
        radix_sort_utils(arr, n, exp);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        radix_sort(arr);
        printarr(arr, size);
    }
}