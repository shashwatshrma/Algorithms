#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

void createGraph(vector<tuple<int, int, int>> &graph, int &vertices)
{
    int sourceNode, destinationNode, weight;
    char choice;
    while(1)
    {
        cin>>weight>>sourceNode>>destinationNode;
        if(sourceNode < vertices && destinationNode < vertices)
            graph.push_back(make_tuple(weight, sourceNode, destinationNode));
        else
            cout<<"Invalid source or destination node!"<<'\n';
        cin>>choice;
        if(choice=='n'||choice=='N')
            break;
    }
}

void bellmanFord(vector<tuple<int, int, int>> &graph, int vertices, int source)
{
    vector<int> parent(vertices, -1);
    vector<int> dist(vertices, INT_MAX);
    dist[source]=0;
    parent[source]=0;
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            int u=get<1>(graph[j]),v=get<2>(graph[j]), w=get<0>(graph[j]);
            if(dist[u]!=INT_MAX && dist[v] > w + dist[u])
            {
                dist[v]=w+dist[u];
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<dist.size();i++)
    {
        cout<<source<<"->"<<i<<": "<<dist[i]<<'\n';
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

void printGraph(vector<tuple<int, int, int>> &graph)
{
    for(auto edge: graph)
    {
        cout<<get<1>(edge)<<" -> "<<get<2>(edge)<<"("<<get<0>(edge)<<")"<<'\n';
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<tuple<int, int, int>> graph;
    createGraph(graph, vertices);
    printGraph(graph);
    bellmanFord(graph, vertices, 0);
    return 0;
}