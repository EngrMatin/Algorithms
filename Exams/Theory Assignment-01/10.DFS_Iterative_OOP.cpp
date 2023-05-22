// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices reachable from s.
#include<bits/stdc++.h>
using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS(int s);  // prints all vertices in DFS manner from a given source.
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}

// prints all not yet visited vertices reachable from s
void Graph::DFS(int s)
{
    // Initially mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node.
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        int s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

int main()
{
    Graph g(6);         // Total 6 vertices in graph
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(5, 4);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(0, 2);
    g.addEdge(4, 2);
    g.addEdge(2, 3);

    cout << "The DFS traversal is \n";
    g.DFS(1);

    return 0;
}

/*

Output:

The DFS traversal is
1 4 2 3 0 5

*/
