#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void createGraph(vector<pair<int, int>> &graph, int &vertices)
{
    int sourceNode, destinationNode;
    char choice;
    while(1)
    {
        cin>>sourceNode>>destinationNode;
        if(sourceNode < vertices && destinationNode < vertices)
            graph.push_back(make_pair(sourceNode, destinationNode));
        else
            cout<<"Invalid source or destination node!"<<'\n';
        cin>>choice;
        if(choice=='n'||choice=='N')
            break;
    }
}

void printGraph(vector<pair<int, int>> &graph)
{
    for(auto edge: graph)
    {
        cout<<get<0>(edge)<<" -> "<<get<0>(edge)<<'\n';
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<pair<int, int>> graph;
    createGraph(graph, vertices);
    printGraph(graph);
    return 0;
}