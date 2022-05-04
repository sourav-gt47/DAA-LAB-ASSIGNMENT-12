#include <bits/stdc++.h>
using namespace std;

bool bellman_ford(int start, map<pair<int,int>,int>& edges,
                  vector<int>& dist,
                  int V)
{
    for (int i=0; i < V; i++)
    {
        for (auto e : edges)
        {
            int u = e.first.first;
            int v = e.first.second;
            int weight = e.second;
            if (dist[u] != INT_MAX && (dist[v] > dist[u] + weight))
               dist[v] = dist[u] + weight;
        }
    }
    for (auto e : edges)
    {
        int u = e.first.first;
        int v = e.first.second;
        int weight = e.second;
        if (dist[u] != INT_MAX && (dist[v] > dist[u] + weight))
            return false;
    }
    return true;
}

void addEdge(map<pair<int,int>,int>& edges,
             int u, int v, int w)
{
    edges[make_pair(u,v)] = w;
}

int main()
{
    int V = 6;
    // pair of vertex, weight
    map<pair<int,int>,int> edges;

    addEdge(edges, 0, 1, 1);
    addEdge(edges, 1, 2, 1);
    addEdge(edges, 1, 5, 5);
    addEdge(edges, 2, 3, 4);
    addEdge(edges, 2, 4, 1);
    addEdge(edges, 4, 3, 2);
    addEdge(edges, 5, 0, 1);
    addEdge(edges, 5, 4, 4);
 

    vector<int> dist(V, INT_MAX);
    int start = 0;
    dist[start] = 0;
    bool res = bellman_ford(start, edges, dist, V);
    if (!res)
        cout << "Negative-weight cycle exists" << endl;
    else
    {
        cout << "Shortest path distance from start vertex (" << "S"<< ")" << endl;
        cout << "S" <<"-"<< "S"<<" : " << dist[0] << endl;
        for (int i=1; i < V; i++)
            cout << "S" << "-" <<char(i + 64)  << " : " << dist[i] << endl;
    }
    return 0;
}
