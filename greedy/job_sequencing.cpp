#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int max_element(vector<tuple<int, int, int>> &arr, int n)
{
    int max = get<1>(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (max < get<1>(arr[i]))
            max = get<1>(arr[i]);
    }
    return max;
}

bool isPossible(vector<int> &time, int deadline)
{
    for (int i = deadline - 1; i >= 0; i--)
    {
        if (time[i] == 0)
        {
            time[i] = 1;
            return true;
        }
    }
    return false;
}

vector<int> job_sequencing(vector<tuple<int, int, int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), [&](auto &a, auto &b)
         { return get<1>(a) < get<1>(b); });
    int n = jobs.size(), profit = 0;
    vector<int> selected;
    vector<int> time(max_element(jobs, n));
    for (int i = 0; i < n; i++)
    {
        if (isPossible(time, get<1>(jobs[i])))
        {
            selected.push_back(get<0>(jobs[i]));
            profit += get<2>(jobs[i]);
        }
    }
    cout << "Maximum profit possible: " << profit << '\n';
    return selected;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<tuple<int, int, int>> jobs;
        int deadline, profit;
        for (int i = 0; i < size; i++)
        {
            cin >> deadline >> profit;
            jobs.push_back({i + 1, deadline, profit});
        }
        vector<int> res = job_sequencing(jobs);
        int n = res.size();
        cout << n << " jobs selected: ";
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}