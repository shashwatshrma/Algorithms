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
                graph[sourceNode].push_back(destinationNode);
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cin>>choice;
            if(choice=='n'||choice=='N')
                break;
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
    cout<<"finished"<<endl;
    return 0;
}