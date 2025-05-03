#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 6;      // Number of nodes (you can change this)
vector<int> graph[N]; // Adjacency list
bool visited[N];
stack<int> topoStack;

// DFS function
void dfs(int node)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }

    topoStack.push(node); // Push after visiting all neighbors
}

int main()
{
    // Example DAG
    graph[5].push_back(0);
    graph[5].push_back(2);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    // Initialize visited to false
    for (int i = 0; i < N; i++)
        visited[i] = false;

    // Call DFS for unvisited nodes
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    // Print topological order
    cout << "Topological Sort: ";
    while (!topoStack.empty())
    {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }

    return 0;
}
