#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void createGraph(vector<vector<int>> &graph)
{
    int destinationNode;
    char choice;
    for (int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cin>>choice;
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

class HeirHolzers
{
private:
    vector<vector<int>> graph;
    int vertices;
    vector<int> in, out;
    int start;
    vector<vector<bool>> visited;
    stack<int> traversal;

    int find(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
        int RE = find(parent[i], parent);
        parent[i] = RE;
        return RE;
    }

    void unionize(int i, int j, vector<int> &parent)
    {
        int pi = find(i, parent);
        int pj = find(j, parent);
        if (pi < pj)
            parent[j] = pi;
        else
            parent[i] = pj;
    }

    int getNumberOfConnectedComponents()
    {
        vector<int> parent(vertices);
        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < vertices; i++)
        {
            for (auto edge : graph[i])
            {
                if (find(i, parent) != find(edge, parent))
                    unionize(i, edge, parent);
            }
        }
        int count = 1;
        for (int i = 1; i < vertices; i++)
        {
            if (parent[i] != parent[i - 1])
                count++;
        }
        return count;
    }

    int findValidStart()
    {
        int vertices = graph.size();
        for (int i = 0; i < vertices; i++)
        {
            if (graph[i].size() != 0)
                return i;
        }
        return -1;
    }
    
    void traverse(int source)
    {
        traversal.push(source);
        for(int i=0;i < graph[source].size();i++)
        {
            if(!visited[source][i])
            {
                visited[source][i]=true;
                traverse(graph[source][i]);
            }
        }
    }

public:
    HeirHolzers(vector<vector<int>> &graph)
    {
        this->graph = graph;
        vertices = graph.size();
        in = vector<int>(vertices, 0);
        out = vector<int>(vertices, 0);
        start = findValidStart();
        visited = vector<vector<bool>>();
        for(int i=0;i<vertices;i++)
        {
            visited.push_back(vector<bool>(graph[i].size(), false));
        }
    }

    bool eulerianPathExists()
    {
        if (getNumberOfConnectedComponents() > 1)
            return false;
        for (int i = 0; i < vertices; i++)
        {
            for (auto edge : graph[i])
            {
                out[i]++;
                in[edge]++;
            }
        }
        bool startFound = false, endFound = false;
        for (int i = 0; i < vertices; i++)
        {
            if (in[i] - out[i] == 1)
            {
                if (endFound)
                    return false;
                endFound = true;
            }
            else if (out[i] - in[i] == 1)
            {
                if (startFound)
                    return false;
                start = i;
                startFound = true;
            }
            else if (in[i] != out[i])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findEulerianPath()
    {
        if (!eulerianPathExists())
            return vector<int>();
        if (start == -1)
            return vector<int>(vertices);
        vector<int> path;
        traverse(start);
        while (!traversal.empty())
        {
            path.push_back(traversal.top());
            traversal.pop();
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

void printVector(vector<int> &vec)
{
    for (auto val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int vertices;
    cin >> vertices;
    vector<vector<int>> graph(vertices);
    createGraph(graph);
    printGraph(graph);
    HeirHolzers *ins = new HeirHolzers(graph);
    vector<int> path = ins->findEulerianPath();
    printVector(path);
    return 0;
}
/*
Test data:
5
y
1
n
y
2
y
3
n
y
1
n
y
4
n
n
*/