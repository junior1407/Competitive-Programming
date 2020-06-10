// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1344/problem/B


#include "bits/stdc++.h"
using namespace std;

const int kMaxN = 1024;
char board[kMaxN][kMaxN];
bool vis[kMaxN][kMaxN];
int H, W;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

void Dfs(int r, int c) {
    vis[r][c] = true;
    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nc < 0 || nr >= H || nc >= W) {
            continue;
        }
        if (board[nr][nc] == '#' && !vis[nr][nc]) {
            Dfs(nr, nc);
        }
    }
}

int main() {


    scanf("%d %d",&H,&W);
    for (int i = 0; i < H; ++i) {
        cin >> board[i];
    }

    bool anyc = false, anyr = false;

    for (int r = 0; r < H; ++r) {
        int minc = 1e9, maxc = -1e9, numc = 0;
        for (int c = 0; c < W; ++c) {
            if (board[r][c] == '#') {
                minc = min(minc, c);
                maxc = max(maxc, c);
                ++numc;
            }
        }

        if (numc > 0 && maxc - minc + 1 != numc) {
            printf("-1\n");
            return 0;
        }
        anyc |= (numc == 0);
    }

    for (int c = 0; c < W; ++c) {
        int minr = 1e9, maxr = -1e9, numr = 0;
        for (int r = 0; r < H; ++r) {
            if (board[r][c] == '#') {
                minr = min(minr, r);
                maxr = max(maxr, r);
                ++numr;
            }
        }

        if (numr > 0 && maxr - minr + 1 != numr) {
            printf("-1\n");
            return 0;
        }
        anyr |= (numr == 0);
    }

    if (anyc != anyr) {
        printf("-1\n");
        return 0;
    }

    int ncompos = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j] && board[i][j] == '#') {
                Dfs(i, j);
                ++ncompos;
            }
        }
    }
    printf("%d\n",ncompos);
}