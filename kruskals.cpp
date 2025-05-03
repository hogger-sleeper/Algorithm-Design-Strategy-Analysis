#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

const int V = 5; // Number of vertices
int parent[V];

// Find root of a node
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// Union two sets
void unite(int x, int y)
{
    parent[find(x)] = find(y);
}

int main()
{
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    // Initialize each vertex to be its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edge \tWeight\n";
    for (Edge e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            cout << e.u << " - " << e.v << "\t" << e.weight << "\n";
            unite(e.u, e.v);
        }
    }

    return 0;
}
