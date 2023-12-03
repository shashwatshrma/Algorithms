#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> activity_selection(vector<tuple<int, int, int>> &activities)
{
    sort(activities.begin(), activities.end(), [&](auto &a, auto &b)
    {
        return get<2>(a) < get<2>(b);
    });
    int n = activities.size(), currEnd = 0;
    vector<int> selected;
    for (int i = 0; i < n; i++)
    {
        if (get<1>(activities[i]) >= currEnd)
        {
            selected.push_back(get<0>(activities[i]));
            currEnd = get<2>(activities[i]);
        }
    }
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
        vector<tuple<int, int, int>> activities;
        int start, end;
        for (int i = 0; i < size; i++)
        {
            cin >> start >> end;
            activities.push_back({i + 1, start, end});
        }
        vector<int> res = activity_selection(activities);
        int n = res.size();
        cout<<n<<" activities selected: ";
        for (int i = 0; i < n; i++)
        {
            cout<<res[i]<<' ';
        }
        cout<<'\n';
    }
}