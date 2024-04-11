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

void floydWarshall(vector<tuple<int, int, int>> &graph, int vertices)
{
    vector<vector<int>> dist(vertices), parent(vertices);
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            if(i==j)
            {
                dist[i].push_back(0);
                parent[i].push_back(i);
            }
            dist[i].push_back(INT_MAX);
            parent[i].push_back(-1);
        }
    }
    
    for(int i=0;i<graph.size();i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            for (int k = 0; k < graph.size(); k++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] > dist[i][k] + dist[k][j];
                }
                
            }
            
        }
        
    }

    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cout<<i<<" -> "<<j<<": "<<dist[i][j]<<endl;
        }
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
    floydWarshall(graph, vertices);
    return 0;
}