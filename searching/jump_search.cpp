#include <iostream>
#include <vector>
#include <cmath>

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

int jump_search(vector<int> &a, int ele)
{
	int n = a.size();
	int bs = sqrt(n);
	int i;
    for(i=0;i+bs<n;i+=bs)
	{
		if(a[i+bs-1] >= ele)
		{
			return binary_search_utils(a, i, i+bs-1, ele);
		}
	}
    return binary_search_utils(a, n-bs, n-1, ele);
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
    cout << jump_search(arr, ele);
    return 0;
}