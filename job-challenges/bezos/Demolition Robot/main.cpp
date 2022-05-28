#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define ppiii pair<pair<int, int>, int>
#define TARGET 9
#define BLOCKED 0


int solve(vvi maze) {
    int n = maze.size(), m = maze[0].size();
    //printf("%d %d\n\n", n, m);
    vvi visited(n);
    for (int i = 0; i < n; i++) {
        visited[i].resize(m);
    }
    vector<pii> directions = {{-1, 0}, {1,0}, {0, 1}, {0, -1}};
    queue<ppiii> q; q.push({{0,0}, 0}); //
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        //printf("%d %d\n", x, y);
        int distance = q.front().second;
        q.pop();
        if (maze[x][y] == TARGET) {
            return distance;
        }
        for (auto d: directions) {
            int new_x = x + d.first, new_y = y + d.second;
            //printf("  Considering %d %d %d\n", new_x, new_y);
            if ((new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) && 
                (maze[new_x][new_y] != BLOCKED) && visited[new_x][new_y] != 1) {
                    visited[new_x][new_y] = 1;
                    q.push({{new_x, new_y}, distance+1});
                }
        }

    }
    return -1;
}

void test(int expected, int obtained) {
    if (expected == obtained) {
        printf("CORRECT\n");
    } else {
        printf("INCORRECT %d %d\n", expected, obtained);
    }
}

int main() {

    vvi c1 = {
        {1,0,0},
        {1,0,0},
        {1,9,1}};
    vvi c2 = {
        {1,1,1,1},
        {0,1,1,1},
        {0,1,0,1},
        {1,1,9,1}, 
        {0,0,1,1}};
    test(3, solve(c1));
    test(5, solve(c2));
    return 0;
}