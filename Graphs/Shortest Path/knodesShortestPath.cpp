#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void createGraph(vector<vector<pair<int, int>>> &graph)
{
    int destinationNode, weight;
    char choice;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        while(1)
        {
            cin>>destinationNode>>weight;
            if(destinationNode < graph.size())
            {
                graph[sourceNode].push_back({destinationNode, weight});
                graph[destinationNode].push_back({sourceNode, weight});
            }
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cin>>choice;
            if(choice=='n'||choice=='N')
                break;
        }
    }
}

void pprint(vector<int> parent, int source, int i)
{
    if(i == source || parent[i] == -1)
    {
        cout<<i<<'\n';
        return;
    }
    pprint(parent, source, parent[i]);
    cout<<i<<" ";
}

void DLDFSutils(
    vector<vector<pair<int, int>>> &graph, int source, int &destination,
    int depth, int curr, int &minPath, vector<bool> &visited, 
    vector<int> currPath, vector<int> &minParent
    )
{
    if(depth==0) return;
    if(source==destination)
    {
        if(curr<minPath)
        {
            curr=minPath;
            currPath=minParent;
        }
    }
    for(int i=0; i<graph[source].size();i++)
    {
        if(visited[graph[source][i].first] == false)
        {
            currPath[graph[source][i].first]=source;
            DLDFSutils(graph, source, destination, depth-1, curr+graph[source][i].second, minPath, visited, currPath, minParent);
        }
    }
}

void DLDFS(vector<vector<pair<int, int>>> &graph, int source, int destination, int depth)
{
    vector<bool> visited(graph.size(),false);
    vector<int> currPath(graph.size(),-1);
    vector<int> minParent(graph.size(),-1);
    int minPath=INT_MAX;
    DLDFSutils(graph, source, destination, depth, 0, minPath, visited, currPath, minParent);
    pprint(minParent, source, destination);
}

int main()
{
    int vertices, source, destination, k;
    cin>>vertices;
    vector<vector<pair<int, int>>> graph(vertices);
    createGraph(graph);
    cin>>source>>destination>>k;
    DLDFS(graph, source, destination, k);
    return 0;
}
