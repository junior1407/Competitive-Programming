// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
#include <bits/stdc++.h>
using namespace std;
#define inf 1e5 + 10;
#define pii pair<int, int>
#define trii pair<int, pii>

bool isValid(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}
int bfs(int n, int a, int b)
{
    queue<trii> q;
    map<pii, int> visited;
    vector<pii> dirs = {{a, b}, {-a, b}, {-a, -b}, {a, -b}, {b, a}, {-b, a}, {-b, -a}, {b, -a}};
    q.push({0, {0, 0}});
    while (!q.empty())
    {
        int k = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == n - 1 && y == n - 1)
        {
            return k;
        }
        for (pii d : dirs)
        {
            int new_x = x + d.first;
            int new_y = y + d.second;
            if (isValid(new_x, new_y, n))
            {
                if (visited.count({new_x, new_y}) == 0)
                {
                    visited[{new_x, new_y}] = 1;
                    q.push({ k+1 , {new_x, new_y}});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    int ans;
    map<pair<int, int>, int> memo;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            auto it = memo.find({j, i});
            if (it != memo.end())
            {
                ans = it->second;
            }
            else
            {
                ans = bfs(n, i, j);
                memo[{i, j}] = ans;
            }
            printf("%d%c", ans, j + 1 == n ? '\n' : ' ');
        }
    }
}