#include <iostream>
#include <vector>
#include <tuple>

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

void printGraph(vector<tuple<int, int, int>> &graph)
{
    for(auto edge: graph)
    {
        cout<<get<1>(edge)<<" -> "<<get<2>(edge)<<"("<<get<0>(edge)<<"), "<<'\n';
    }
    cout<<"\b\b ";
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<tuple<int, int, int>> graph;
    createGraph(graph, vertices);
    printGraph(graph);
    return 0;
}