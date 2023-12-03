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

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void selection_sort(vector<int> &arr)
{
    int n = arr.size(), min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
    }
}

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] >= key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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

void count_sort_unstable(vector<int> &arr)
{
    int n = arr.size(), max = max_element(arr, n);
    vector<int> count(max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 0, k = 0; i < max + 1; i++)
    {
        while (count[i] != 0)
        {
            arr[k++] = i;
            count[i]--;
        }
    }
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

void radix_sort_utils(vector<int> &arr, int n, int exp)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] / exp % 10 > key / exp % 10 && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
        // vector<float> arr(size);
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        // bubble_sort(arr);
        // selection_sort(arr);
        // insertion_sort(arr);
        // quick_sort(arr);
        // merge_sort(arr);
        // heap_sort(arr);
        // count_sort_unstable(arr);
        // count_sort_stable(arr);
        // bucket_sort(arr);
        radix_sort(arr);
        printarr(arr, size);
    }
}