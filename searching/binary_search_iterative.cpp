#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int ele)
{
	int l = 0, u = a.size() - 1, m;
	while(l <= u)
	{
		m = (l + u)/2;
		if(a[m] == ele)
			return m;
		else if(a[m] < ele)
			l = m + 1;
		else
			u = m - 1;
	}
	return -1;
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