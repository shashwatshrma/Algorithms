#include <iostream>
#include <vector>

using namespace std;

int linear_search(vector<int> &arr, int ele)
{
	int n = arr.size();
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == ele)
			return i;
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
    cout << linear_search(arr, ele);
    return 0;
}