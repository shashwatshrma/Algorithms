#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void createGraph(vector<vector<int>> &graph)
{
    int destinationNode;
    char choice;
    for(int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cout<<"Enter for "<<sourceNode<<"?: ";
        cin>>choice;
        while(choice!='n' && choice!='N')
        {
            cout<<"Enter destination: ";
            cin>>destinationNode;
            if(destinationNode < graph.size())
                graph[sourceNode].push_back(destinationNode);
            else
                cout<<"Invalid source or destination node!"<<'\n';
            cout<<"Continue?: ";
            cin>>choice;
        }
    }
}

void topologicalSortUtils(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st, int node)
{
    visited[node]=true;
    for(int j=0;j<graph[node].size();j++)
    {
        if(visited[graph[node][j]]==false)
            topologicalSortUtils(graph, visited, st, graph[node][j]);
    }
    st.push(node);
}

void topologicalSort(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    for(int i=0;i<graph.size();i++)
    {
        if(visited[i] == false)
            topologicalSortUtils(graph, visited, st, i);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" -> ";
        st.pop();
    }
    cout<<"\b\b\b   \n";
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
    topologicalSort(graph);
    cout<<"finished"<<endl;
    return 0;
}