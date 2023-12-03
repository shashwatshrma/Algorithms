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

void merge(vector<int> &arr, int l, int m, int u)
{
    int ls = m - l, rs = u - m + 1;
    int L[ls], R[rs];
    int k = 0;
    for (int i = l; i < m; i++)
    {
        L[k++] = arr[i];
    }
    k = 0;
    for (int i = m; i <= u; i++)
    {
        R[k++] = arr[i];
    }
    k = l;
    int i = 0, j = 0;
    while (i < ls && j < rs)
    {
        if (L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < ls)
    {
        arr[k++] = L[i++];
    }
    while (j < rs)
    {
        arr[k++] = R[j++];
    }
}

void merge_sort_utils(vector<int> &arr, int l, int u)
{
    if (l >= u)
        return;
    int m = (l + u) / 2;
    merge_sort_utils(arr, l, m);
    merge_sort_utils(arr, m + 1, u);
    merge(arr, l, m + 1, u);
}

void merge_sort(vector<int> &arr)
{
    merge_sort_utils(arr, 0, arr.size() - 1);
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
        merge_sort(arr);
        printarr(arr, size);
    }
}