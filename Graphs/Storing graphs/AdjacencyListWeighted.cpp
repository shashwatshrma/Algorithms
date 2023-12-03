#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void createGraph(vector<vector<pair<int, int>>> &graph)
{
    int destinationNode, edgeWeight;
    char choice;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        while(1)
        {
            cin>>destinationNode>>edgeWeight;
            if(destinationNode < graph.size())
                graph[sourceNode].push_back(make_pair(destinationNode, edgeWeight));
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cin>>choice;
            if(choice=='n'||choice=='N')
                break;
        }
    }
}

void printGraph(vector<vector<pair<int, int>>> &graph)
{
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cout<<sourceNode<<": ";
        for(int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
            cout<<graph[sourceNode][destinationNode].first<<"("<<graph[sourceNode][destinationNode].first<<"), ";
        cout<<"\b\b "<<'\n';
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<vector<pair<int, int>>> graph(vertices);
    createGraph(graph);
    printGraph(graph);
    return 0;
}