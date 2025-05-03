#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, weight;
};

int main()
{
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    int source = 0;
    vector<int> dist(V, INF);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
        {
            cout << "Graph contains a negative weight cycle!" << endl;
            return 0;
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "To vertex " << i << " = ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
