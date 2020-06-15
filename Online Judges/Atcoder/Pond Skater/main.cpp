// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://atcoder.jp/contests/abc170/tasks/abc170_d

#include <bits/stdc++.h>
using namespace std;

// U, R, D, L
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct State { int currDistance, prevDir, x, y; };
struct StateComparator{
    bool operator()(State const& s1,State const& s2 ){
        return s1.currDistance > s2.currDistance;
    }
};
int main() {
    int H,W,K ;
    scanf("%d%d%d",&H,&W, &K);
    int x1, y1, x2, y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x1--;
    y1--;
    y2--;
    x2--;
    vector<vector<char> > board(H, vector<char>(W, '.'));
    vector<vector<int> > dist(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
    // we start at (x1,y1) and want to go to (x2,y2)
    dist[x1][y1] = 0;
    priority_queue<State, vector<State>, StateComparator> pq;
    pq.push(State{0, -1 ,x1,y1});
    while(pq.size() > 0){
        State s = pq.top();
        pq.pop();
        if (s.currDistance != dist[s.x][s.y]){
            continue; // if it`s been already processed
        }
        if (s.x == x2 && s.y == y2){
            break;
        }
        for(int i = 0; i< 4; i++){
            if ((i + 2) % 4 == s.prevDir || i == s.prevDir) {
                continue;
            }
            for(int k = 1 ; k <= max(H, W); k++){
                int newx = s.x + dx[i] * k;
                int newy = s.y + dy[i] * k;
                if (newx < 0 || newy < 0 || newx >= H || newy >= W){
                    break;
                }
                if (board[newx][newy] == '@') break;
                int new_d = s.currDistance + (k + K - 1) / K;
                if (dist[newx][newy] == -1 || dist[newx][newy] > new_d) {
                    dist[newx][newy] = new_d;
                    pq.push(State{new_d, i, newx, newy});
                }
            }
        }
    }
    printf("%d\n", dist[x2][y2]);

}