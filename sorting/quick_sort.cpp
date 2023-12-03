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

int partition(vector<int> &arr, int l, int u)
{
    int i = l - 1, j = l;
    register int key = arr[u];
    while (j < u)
    {
        if (arr[j] <= key)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[u]);
    return i + 1;
}

void quick_sort_utils(vector<int> &arr, int l, int u)
{
    if (l > u)
        return;
    int pivot = partition(arr, l, u);
    quick_sort_utils(arr, l, pivot - 1);
    quick_sort_utils(arr, pivot + 1, u);
}

void quick_sort(vector<int> &arr)
{
    quick_sort_utils(arr, 0, arr.size() - 1);
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
        quick_sort(arr);
        printarr(arr, size);
    }
}