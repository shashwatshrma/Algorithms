#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void createGraph(vector<tuple<int, int, int>> &graph, int &vertices)
{
    int sourceNode, destinationNode, weight;
    char choice;
    while(1)
    {
        cin>>weight>>sourceNode>>destinationNode;
        if(sourceNode < vertices && destinationNode < vertices)
        {
            graph.push_back(make_tuple(weight, sourceNode, destinationNode));
            graph.push_back(make_tuple(weight, destinationNode, sourceNode));
        }
        else
            cout<<"Invalid source or destination node!"<<'\n';
        cin>>choice;
        if(choice=='n'||choice=='N')
            break;
    }
}

int find(vector<int> &parent, int &u)
{
    if(parent[u]==u)
        return u;
    int RE=find(parent, parent[u]);
    parent[u]=RE;
    return RE;
}

void unionize(vector<int> &parent, int &u, int &v)
{
    int pu=find(parent, u), pv=find(parent, v);
    for(int i=0;i<parent.size();i++)
        if(parent[i]==pu)
            parent[i]=pv;
}

int kruskal(vector<tuple<int, int, int>> graph, int &vertices)
{
    vector<int> parent(vertices);
    for(int i=0;i<vertices;i++)
        parent[i]=i;
    sort(graph.begin(), graph.end());
    int msw=0;
    for(int i=0,j=0;j<vertices-1;i++)
    {
        int u = get<1>(graph[i]);
        int v = get<2>(graph[i]);
        if(find(parent, u) == find(parent, v))
            continue;
        msw+=get<0>(graph[i]);
        unionize(parent, u, v);
        j++;
    }
    return msw;
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<tuple<int, int, int>> graph;
    createGraph(graph, vertices);
    cout<<"Minimum Spanning Weight: "<<kruskal(graph, vertices);
    return 0;
}