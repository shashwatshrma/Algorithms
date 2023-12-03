#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> fractional_knapsack(vector<tuple<int, int, int>> &items, int cap)
{
    sort(items.begin(), items.end(), [&](auto &a, auto &b)
    {
        return get<2>(a)/get<1>(a) > get<2>(b)/get<1>(b);
    });
    int n = items.size(), currEnd = 0;
    vector<int> selected;
    double profit=0;
    for(int i=0;i<n && cap!=0;i++)
    {
        selected.push_back(get<0>(items[i]));
        if(cap<get<1>(items[i]))
        {
            profit+=1.0*get<2>(items[i])/get<1>(items[i]) * cap;
            cap=0;
            break;
        }
        cap-=get<1>(items[i]);
        profit+=get<2>(items[i]);
    }
    cout<<"Maximum profit possible: "<<profit<<'\n';
    return selected;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size, cap;
        cin >> size;
        vector<tuple<int, int, int>> items;
        int weight, value;
        for (int i = 0; i < size; i++)
        {
            cin >> weight >> value;
            items.push_back({i + 1, weight, value});
        }
        cin>>cap;
        vector<int> res = fractional_knapsack(items, cap);
        int n=res.size();
        cout<<"Items selected: ";
        for (int i = 0; i < n; i++)
        {
            cout<<res[i]<<' ';
        }
        cout<<'\n';
    }
}
