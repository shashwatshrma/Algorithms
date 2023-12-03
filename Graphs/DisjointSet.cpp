#include <iostream>
#include <vector>

using namespace std;

void createGraph(vector<vector<int>> &graph)
{
    int destinationNode;
    char choice;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cin>>choice;
        while(choice!='n')
        {
            cin>>destinationNode;
            if(destinationNode < graph.size())
            {
                //graph[destinationNode].push_back(sourceNode);
                graph[sourceNode].push_back(destinationNode);
            }
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cin>>choice;
        }
    }
}

int find(int &u, vector<int> &parent);
void unionNodes(int &u, int &v, vector<int> &parent);

void makeDisjoint(vector<vector<int>> &graph)
{
    vector<int> parent(graph.size());
    for(int node = 0; node < graph.size(); node++)
    {
        parent[node]=node;
    }
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        for(int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
        {
            if(find(sourceNode, parent)!=find(graph[sourceNode][destinationNode], parent))
            {
                unionNodes(sourceNode, graph[sourceNode][destinationNode], parent);
            }
            else
            {
                cout<<"Cycle exists"<<'\n';
            }
        }
    }
    for(int node = 0; node < graph.size(); node++)
    {
        cout<<node<<": "<<parent[node]<<'\n';
    }
}

int find(int &u, vector<int> &parent)
{
    if(parent[u]==u)
        return u;
    int RE=find(parent[u], parent);
    parent[u]=RE;
    return parent[u];
}

void unionNodes(int &u, int &v, vector<int> &parent)
{
    int pu=find(u, parent);
    int pv=find(v, parent);
    parent[pv]=pu;
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
    makeDisjoint(graph);
    return 0;
}