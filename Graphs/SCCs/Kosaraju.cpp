#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void createGraph(vector<vector<int>> &graph)
{
    int destinationNode;
    char choice;
    for (int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cin >> choice;
        while (!(choice == 'n' || choice == 'N'))
        {
            cin >> destinationNode;
            if (destinationNode < graph.size())
                graph[sourceNode].push_back(destinationNode);
            else
                cout << "Invalid source or destination node!" << '\n';
            cin >> choice;
        }
    }
}

void printGraph(vector<vector<int>> &graph)
{
    for (int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cout << sourceNode << ": ";
        for (int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
            cout << graph[sourceNode][destinationNode] << " ";
        cout << '\n';
    }
}

class Kosaraju
{
    vector<vector<int>> graph;
    vector<vector<int>> reverse;
    int vertices, count;
    vector<vector<int>> SCCs;
    stack<int> finishing_time;

    vector<vector<int>> reverseGraph(vector<vector<int>> graph)
    {
        vector<vector<int>> rev(vertices);
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                rev[graph[i][j]].push_back(i);
            }
        }
        return rev;
    }

    void DFS(vector<vector<int>> &graph, stack<int> &st)
    {
        vector<bool> visited(graph.size(), false);
        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
                DFSUtils(graph, visited, i, st);
        }
    }

    void DFSUtils(vector<vector<int>> &graph, vector<bool> &visited, int &source, stack<int> &st)
    {
        visited[source] = true;
        for (int i = 0; i < graph[source].size(); i++)
        {
            if (visited[graph[source][i]] == false)
            {
                DFSUtils(graph, visited, graph[source][i], st);
            }
        }
        st.push(source);
    }

public:
    Kosaraju(vector<vector<int>> &graph)
    {
        this->graph = graph;
        vertices = graph.size();
        reverse = reverseGraph(graph);
        count = 0;
    }

    void run()
    {
        vector<bool> visited(vertices, false);
        stack<int> st;
        int curr;
        DFS(graph, finishing_time);
        while (!finishing_time.empty())
        {
            curr = finishing_time.top();
            finishing_time.pop();
            if (visited[curr])
            {
                continue;
            }
            count++;
            DFSUtils(reverse, visited, curr, st);
            vector<int> temp;
            while (!st.empty())
            {
                temp.push_back(st.top());
                st.pop();
            }
            SCCs.push_back(temp);
        }
    }

    int getNumberOfSCCs()
    {
        return count;
    }

    void printSCCs()
    {
        for (int i = 0; i < SCCs.size(); i++)
        {
            for (auto node : SCCs[i])
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int vertices;
    cin >> vertices;
    vector<vector<int>> graph(vertices);
    createGraph(graph);
    printGraph(graph);
    Kosaraju *ins = new Kosaraju(graph);
    ins->run();
    cout << "The number of connected components in the given graph are: " << ins->getNumberOfSCCs() << endl;
    cout << "The connected components in the given graph are: " << endl;
    ins->printSCCs();
    return 0;
}
/*
8
y
1
n
y
2
n
y
0
y
3
n
y
4
n
y
5
y
7
n
y
6
n
y
4
y
7
n
n
*/