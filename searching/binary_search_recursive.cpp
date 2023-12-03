#include <iostream>
#include <vector>

using namespace std;

int binary_search_utils(vector<int> &a, int l, int u, int ele)
{
    if(l > u) return -1;
	int m = (l + u)/2;
	if(a[m] == ele)
		return m;
	else if(a[m] < ele)
		return binary_search_utils(a, m + 1, u, ele);
	else
		return binary_search_utils(a, l, m - 1, ele);
}

int binary_search(vector<int> &a, int ele)
{
	return binary_search_utils(a, 0, a.size() - 1, ele);
}

int main()
{
    int size, ele;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cin >> ele;
    cout << binary_search(arr, ele);
    return 0;
}