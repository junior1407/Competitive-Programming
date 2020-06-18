// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/bfsshortreach/problem

#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 100;
int nodes, edges;

void addEdge(vector<vector<int>>& graph, int u, int v)
{
    //printf("Addinge edge from %d %d\n", u + 1, v + 1);
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector<vector<int>>& graph, int source)
{
    vector<int> distance(nodes, -1);
    vector<int> visited(nodes, 0);
    queue<int> q;
    q.push(source);
    distance[source] = 0;
    int u, v;
    while (!q.empty())
    {

        u = q.front();
        q.pop();
        if (visited[u] == 1)
        {
            continue;
        }
        visited[u] = 1;
        for (auto v : graph[u])
        {
            if (visited[v] == 0 && distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < nodes; i++)
    {

        if (i == source)
        {
            continue;
        }
        printf("%d%c", distance[i] != -1 ? distance[i] * 6 : -1, i == nodes - 1 ? '\n' : ' ');
    }
}
int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {

        scanf("%d %d", &nodes, &edges);
        vector<vector<int>> graph(nodes);
        int u, v;
        for (int i = 0; i < edges; i++)
        {
            scanf("%d %d", &u, &v);
            u--;
            v--;
            addEdge(graph, u, v);
        }
        int source;
        scanf("%d", &source);
        bfs(graph, source - 1);
    }
    return 0;
}