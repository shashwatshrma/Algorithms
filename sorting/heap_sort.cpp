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

void percolate_down(vector<int> &arr, int i, int n)
{
    int c1 = 2 * i + 1, c2 = 2 * i + 2;
    int maximum = i;
    if (c1 < n && arr[maximum] < arr[c1])
        maximum = c1;
    if (c2 < n && arr[maximum] < arr[c2])
        maximum = c2;
    if (maximum != i)
    {
        swap(arr[i], arr[maximum]);
        percolate_down(arr, maximum, n);
    }
}

void build_heap(vector<int> &arr, int n)
{
    for (int i = (n + 1) / 2; i >= 0; i--)
    {
        percolate_down(arr, i, n);
    }
}

int extract_max(vector<int> &arr, int &n)
{
    int temp = arr[0];
    swap(arr[0], arr[n - 1]);
    n--;
    percolate_down(arr, 0, n);
    return temp;
}

void heap_sort(vector<int> &arr)
{
    int n = arr.size();
    build_heap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        extract_max(arr, n);
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
        heap_sort(arr);
        printarr(arr, size);
    }
}