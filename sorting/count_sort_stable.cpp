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

int max_element(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void count_sort_stable(vector<int> &arr)
{
    int n = arr.size(), max = max_element(arr, n);
    vector<int> count(max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    vector<int> temp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }
    arr = temp;
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
        count_sort_stable(arr);
        printarr(arr, size);
    }
}