// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1365/problem/D

#include<bits/stdc++.h>
using namespace std;
const int N = 50+5;
char arr[N][N];
int dx[] = {0,0,1,-1};
int dy[]=  {1,-1,0,0};
int n,m;
bool isValid(int i, int j){
    if (i >= 0 && i< n){
        if (j>=0 && j < m){
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        getchar();
        for(int i = 0; i <n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%c", &arr[i][j]);
            }
            getchar();
        }
        for(int i = 0; i <n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]=='B'){
                    //check all surroundings and put walls.
                    for(int k = 0; k< 4; k++){
                        int x = i + dx[k]; int y = j + dy[k];
                        if (isValid(x,y) && arr[x][y] == '.'){
                            arr[x][y] = '#';
                        }
                    }
                }
            }
        }
        vector <vector <int>> vis(n, vector <int> (m));
        /* for(int i = 0; i< n; i++){
             for(int j = 0; j < m; j++){
                 printf("%c(%d)", arr[i][j], vis[i][j]);
             }
             printf("\n");
         }*/
        queue <pair <int, int>> q;
        if (arr[n - 1][m - 1] != '#') {
            vis[n - 1][m - 1] = 1;
            q.push({n - 1, m - 1});
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int k = 0; k < 4; ++k) {
                int tx = x + dx[k], ty = y + dy[k];
                //printf("visited : %d")
                if (isValid(tx, ty) && arr[tx][ty] != '#'){
                    if (vis[tx][ty] == 0){
                        vis[tx][ty] = 1;
                        q.push({tx, ty});
                    }
                }
            }
        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == 'G') good &= vis[i][j];
                if (arr[i][j] == 'B') good &= !vis[i][j];
            }
        }
        cout << (good ? "Yes" : "No") << '\n';
    }



    return 0;
}
