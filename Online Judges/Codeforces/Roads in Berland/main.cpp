// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/25/problem/C

#include <bits/stdc++.h>

using namespace std;
int n_edges;
vector<vector<long long int>> distances;
long long ans = 0;
void add(int u, int v, int c){
    if (distances[u][v] <= c){
        return;
    }
    for(int i = 0; i < n_edges; i++ ){
        for(int j = 0; j< n_edges; j++){
            if (distances[i][j] > distances[i][u] + c + distances[v][j]){
                if (i<j){
                    ans = ans - distances[i][j] + distances[i][u] + c + distances[v][j];
                }
                distances[i][j] = distances[i][u] + c + distances[v][j];
            }
        }
    }
}

int main(){
    scanf("%d",&n_edges);
    int x, k, u, v, c;
    distances.resize(n_edges);
    for(int i = 0; i< n_edges; i++){
        distances[i].resize(n_edges);
        for(int j=0 ; j < n_edges ; j++){
            scanf("%d",&x);
            distances[i][j] = x;
            if (i< j){
                ans+=x;
            }
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d %d %d",&u, &v, &c);
        u--;
        v--;
        add(u,v,c);
        add(v,u,c);
        printf("%lld", ans);
        if (k >= 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}