#include <iostream>
#include <vector>

using namespace std;

int maxSubArraySum(vector<int> &nums)
{
    int overallmax = nums[0], runningsum = 0;
    for (auto x : nums)
    {
        if (runningsum < 0)
            runningsum = 0;
        runningsum += x;
        overallmax = max(overallmax, runningsum);
    }
    return overallmax;
}

int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    cout << maxSubArraySum(nums) << endl;
    return 0;
}