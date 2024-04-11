#include <iostream>
#include <vector>

using namespace std;

bool isMajority(vector<int> &nums, int me)
{
    int count=0;
    for(auto n:nums)
    {
        if(n == me)
            count++;
    }
    if(count>nums.size()/2)
        return true;
    return false;
}

int boyer_moore_majority(vector<int> &nums)
{
    int n = nums.size();
    int me = nums[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != me)
        {
            count--;
            if (!count)
            {
                me = nums[i];
                count = 1;
            }
        }
        else
        {
            count++;
        }
    }
    if(isMajority(nums, me))
        return me;
    return -1;
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
        cout << boyer_moore_majority(arr) << endl;
    }
}