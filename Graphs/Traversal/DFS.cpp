#include <iostream>
#include <vector>

using namespace std;

void createGraph(vector<vector<int>> &graph)
{
    int destinationNode;
    char choice;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        while(1)
        {
            cin>>destinationNode;
            if(destinationNode < graph.size())
            {
                graph[sourceNode].push_back(destinationNode);
                graph[destinationNode].push_back(sourceNode);
            }
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cin>>choice;
            if(choice=='n'||choice=='N')
                break;
        }
    }
}

void dfsUtils(vector<vector<int>> &graph, vector<bool> &visited, int &source);

void DFS(vector<vector<int>> &graph, int source)
{
    vector<bool> visited(graph.size(), false);
    dfsUtils(graph, visited, source);
}

void dfsUtils(vector<vector<int>> &graph, vector<bool> &visited, int &source)
{
    visited[source]=true;
    cout<<source<<" ";
    for(int i=0;i<graph[source].size();i++)
    {
        if(visited[graph[source][i]]==false)
        {
            dfsUtils(graph, visited, graph[source][i]);
        }
    }
}

void printGraph(vector<vector<int>> &graph)
{
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cout<<sourceNode<<": ";
        for(int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
            cout<<graph[sourceNode][destinationNode]<<" ";
        cout<<'\n';
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<vector<int>> graph(vertices);
    createGraph(graph);
    printGraph(graph);
    DFS(graph, 0);
    return 0;
}