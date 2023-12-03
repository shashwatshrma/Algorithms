#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printarr(vector<float> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void bucket_sort_utils(vector<float> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while (arr[j] >= key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucket_sort(vector<float> &arr)
{
    vector<vector<float>> buckets(10);
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int ind = n * arr[i];
        buckets[ind].push_back(arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        bucket_sort_utils(buckets[i]);
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
        vector<float> arr(size);
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        bucket_sort(arr);
        printarr(arr, size);
    }
}