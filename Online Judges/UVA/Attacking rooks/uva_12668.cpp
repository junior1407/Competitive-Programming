#include <bits/stdc++.h>
#include <chrono>
using namespace std;
const int maxVertices = 1 + 50*100 + 50*100 + 1;
int n;
#define pii pair<int,int>
/*
source = 0
rows = [1, lastRow+1]
Cols = [lastRow+2, lastRow+lastColumn+2]
target = [lastRow+lastColumn+3]*/

struct Edge { int to, from, flow; };
vector<Edge> graph[maxVertices];
int previous[maxVertices];

void addEdge(int u, int v, int f)
{
    graph[u].push_back({v, (int) graph[v].size(), f});
    graph[v].push_back({u, (int) graph[u].size()-1, 0});
}

bool BFS(int source, int target)
{
    // previous.clear();
    queue<int> q;
    vector<int> visited(target + 1);
    q.push(source);
    visited[source] = 1;
    int u, v, f;
    while (!q.empty())
    {

        u = q.front();
        q.pop();
        if (u == target)
        {
            return true;
        }
        for (auto &e: graph[u])
        {
            v = e.to;
            f = e.flow;
            if (f > 0)
            {
                if (visited[v] != 1)
                {
                    previous[v] = e.from;
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

int fk(int source, int target)
{
    int maxFlow = 0;
    while (BFS(source, target))
    {
        maxFlow++;
        int v, pos, u;
        v = target;
        while (v != source)
        {
            pos = previous[v];
            auto& e = graph[v][pos];
            u = e.to;
            auto &back = graph[u][e.from];
            back.flow -= 1;
            e.flow += 1;
            v = u;
        }
    }
    return maxFlow;
}



int main()
{

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < maxVertices; i ++) graph[i].clear();
        char board[n + 1][n + 1];
        int boardRow[n + 1][n + 1];
        int boardVertical[n + 1][n + 1];
        getchar();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%c", &board[i][j]);
            }
            getchar();
        }
        int colorRow = 0;
        int colorCol = 0;
        int lastRow = 0;
        int lastCol = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'X')
                {
                    boardRow[i][j] = -1;
                    colorRow++;
                }
                else
                {
                    boardRow[i][j] = colorRow;
                    lastRow = colorRow;
                }
                if (board[j][i] == 'X')
                {
                    boardVertical[j][i] = -1;
                    colorCol++;
                }
                else
                {
                    boardVertical[j][i] = colorCol;
                    lastCol = colorCol;
                }
            }
            colorRow++;
            colorCol++;
        }

        int source = 0;
        int target = lastRow + lastCol + 3;
        for (int i = 0; i <= lastRow; i++)
        {
            addEdge(0, i + 1, 1);
        }
        for (int i = 0; i <= lastCol; i++)
        {
            addEdge(lastRow + 2 + i, target, 1);
        }
        int currentRow;
        int currentCol;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'X')
                {
                    addEdge(1 + boardRow[i][j], 2 + lastRow + boardVertical[i][j], 1);
                }

            }
        }

        printf("%d\n", fk(source, target));
    }
    return 0;
}