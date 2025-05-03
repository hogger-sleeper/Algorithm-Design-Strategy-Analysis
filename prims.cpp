#include <iostream>
using namespace std;

const int INF = 1e9;
const int V = 5; // Number of vertices

int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}};

int main()
{
    int parent[V]; // Store MST
    int key[V];    // Used for finding minimum weight edge
    bool inMST[V]; // To keep track of vertices included

    // Initialize all keys to INF and inMST to false
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0;     // Start from vertex 0
    parent[0] = -1; // Root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int minKey = INF, u;

        // Find the vertex with the smallest key not in MST
        for (int v = 0; v < V; v++)
        {
            if (!inMST[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }

    return 0;
}
