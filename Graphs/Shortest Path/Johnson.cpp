#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

void createGraph(vector<vector<pair<int, int>>> &graph)
{
    int destinationNode, edgeWeight;
    char choice;
    for (int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cin >> choice;
        while (choice != 'n')
        {
            cin >> destinationNode >> edgeWeight;
            if (destinationNode < graph.size())
            {
                graph[sourceNode].push_back(make_pair(destinationNode, edgeWeight));
            }
            else
                cout << "Invalid source or destination node!" << '\n';
            cin >> choice;
        }
    }
}

void printGraph(vector<vector<pair<int, int>>> &graph)
{
    for (int sourceNode = 0; sourceNode < graph.size(); sourceNode++)
    {
        cout << sourceNode << ": ";
        for (int destinationNode = 0; destinationNode < graph[sourceNode].size(); destinationNode++)
            cout << graph[sourceNode][destinationNode].first << "(" << graph[sourceNode][destinationNode].second << "), ";
        cout << "\b\b  \n";
    }
}

vector<int> djikstras(vector<vector<pair<int, int>>> &graph, int vertices, int source)
{
    vector<int> parent(vertices, -1);
    vector<int> dist(vertices, INT_MAX);
    vector<bool> fixed(vertices, false);
    dist[source] = 0;
    parent[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    for (int i = 0; i < graph.size(); i++)
    {
        int curr = pq.top().second;
        pq.pop();
        for (int j = 0; j < graph[curr].size(); j++)
        {
            int u = curr, v = graph[curr][j].first, w = graph[curr][j].second;
            if (fixed[v] != true && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

bool bellmanFord(vector<vector<pair<int, int>>> &graph, int vertices, int source, vector<int> &dist)
{
    dist[source] = 0;
    for (int k = 0; k < vertices - 1; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                int u = i, v = graph[i][j].first, w = graph[i][j].second;
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int u = i, v = graph[i][j].first, w = graph[i][j].second;
            if (dist[u] != INT_MAX && dist[v] > w + dist[u])
            {
                return false;
            }
        }
    }

    return true;
}

vector<vector<int>> johnson(vector<vector<pair<int, int>>> graph, int vertices)
{
    vector<vector<int>> dist(vertices);
    vector<int> bf_dist(vertices, INT_MAX);

    /*inserting a dummy node to run bellman ford
     * to check for negative cycles and to reweigh
     * the graph
     */
    graph.push_back(vector<pair<int, int>>());
    vertices++;
    for (int i = 0; i < vertices - 1; i++)
    {
        graph[vertices - 1].push_back({i, 0});
    }
    if (!bellmanFord(graph, vertices, vertices - 1, bf_dist))
    {
        cout << "Negative cycle present in the given graph" << endl;
        return dist;
    }
    graph.pop_back();
    bf_dist.pop_back();
    vertices--;

    // reweighing
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int u = i, v = graph[i][j].first;
            graph[i][j].second += bf_dist[u] - bf_dist[v];
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = djikstras(graph, vertices, i);
        for (int j = 0; j < vertices; j++)
        {
            dist[i][j] += bf_dist[j] - bf_dist[i];
        }
    }

    return dist;
}

int main()
{
    int vertices;
    cin >> vertices;
    vector<vector<pair<int, int>>> graph(vertices);
    createGraph(graph);
    printGraph(graph);
    vector<vector<int>> dist = johnson(graph, vertices);
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < dist[i].size(); j++)
        {
            cout << i << " -> " << j << ": " << dist[i][j] << endl;
        }
    }
    return 0;
}
/*
Positive weights test case:
5
y
1 4
y
3 5
n
y
2 1
y
4 6
n
y
0 2
y
3 3
n
y
2 1
y
4 2
n
y
0 1
y
3 4
n
Negative weights test case:
5
y
1 3
y
2 8
y
4 -4
n
y
4 7
y
3 1
n
y
1 4
n
y
2 -5
y
0 2
n
y
3 6
n
Negative Cycle Tset Case:
3
y
1 1
n
y
2 1
n
y
0 -3
n
*/