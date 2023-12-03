#include <iostream>
#include <vector>
#include <queue>

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

void BFS(vector<vector<int>> &graph, int source, int destination)
{
    queue<int> q;
    vector<int> traversal(graph.size(), -1);
    
    q.push(source);
    traversal[source]=source;
    
    while(!q.empty())
    {
        int curr=q.front();
        for(int i=0;i<graph[curr].size();i++)
        {
            int connectedNode=graph[curr][i];
            if(traversal[connectedNode]==-1)
            {
                traversal[connectedNode]=curr;
                q.push(connectedNode);
            }
        }
        q.pop();
    }
    pprint(traversal, destination);
}

void pprint(vector<int> parent, int i)
{
    if(parent[i] == i)
    {
        cout<<i<<'\n';
        return;
    }
    pprint(parent, parent[i]);
    cout<<" "<<i;
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
    BFS(graph, 0, 4);
    return 0;
}