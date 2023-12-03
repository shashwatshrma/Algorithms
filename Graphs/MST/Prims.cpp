#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

void createGraph(vector<vector<pair<int, int>>> &graph)
{
    int destinationNode, edgeWeight;
    char choice;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cin>>choice;
        while(choice!='n')
        {
            cin>>destinationNode>>edgeWeight;
            if(destinationNode < graph.size())
            {
                graph[sourceNode].push_back(make_pair(destinationNode, edgeWeight));
                graph[destinationNode].push_back(make_pair(sourceNode, edgeWeight));
            }
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cin>>choice;
        }
    }
}

void prims(vector<vector<pair<int, int>>> &graph, int vertices, int source)
{
    vector<int> parent(vertices, -1);
    vector<int> dist(vertices, INT_MAX);
    vector<bool> fixed(vertices, false);
    dist[source]=0;
    parent[source]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    for(int i=0;i<graph.size();i++)
    {
        int curr=pq.top().second;
        pq.pop();
        fixed[curr]=true;
        for(int j=0;j<graph[curr].size();j++)
        {
            int u=curr,v=graph[curr][j].first, w=graph[curr][j].second;
            if(fixed[v]!=true && dist[v] > w)
            {
                dist[v]=w;
                parent[v]=u;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=0;i<dist.size();i++)
    {
        cout<<parent[i]<<"->"<<i<<": "<<dist[i]<<'\n';
    }
    for(int i=0;i<parent.size();i++)
    {
        cout<<i<<" ";
    }
    cout<<'\n';
    for(int i=0;i<parent.size();i++)
    {
        cout<<parent[i]<<" ";
    }
}

void printGraph(vector<vector<pair<int, int>>> &graph)
{
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cout<<sourceNode<<": ";
        for(int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
            cout<<graph[sourceNode][destinationNode].first<<"("<<graph[sourceNode][destinationNode].second<<"), ";
        cout<<"\b\b  \n";
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<vector<pair<int, int>>> graph(vertices);
    createGraph(graph);
    printGraph(graph);
    prims(graph, vertices, 0);
    return 0;
}