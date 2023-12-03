#include <iostream>
#include <vector>

using namespace std;

void createGraph(vector<vector<int>> graph)
{
    int connectionPresent;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        for(int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
        {
            cin>>connectionPresent;
            graph[sourceNode][destinationNode]=connectionPresent;
        }
    }
}

void printGraph(vector<vector<int>> graph)
{
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        for(int destinationNode = 0; destinationNode < graph.size(); destinationNode++)
            cout<<graph[sourceNode][destinationNode]<<" ";
        cout<<'\n';
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<vector<int>> graph(vertices);
    for(int i=0;i<vertices;i++)
    {
        vector<int> temp(vertices);
        graph.push_back(temp);
    }
    createGraph(graph);
    printGraph(graph);
    return 0;
}