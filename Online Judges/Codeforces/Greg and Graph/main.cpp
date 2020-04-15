// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/295/problem/B


#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
int main(){
    int n_vertices;
    scanf("%d",&n_vertices);
    vector<long long int> ans(n_vertices);
    vector<vector<int>> adj (n_vertices);
    for(int i = 0; i< n_vertices; i++){
        adj[i].resize(n_vertices);
        for (int j = 0; j< n_vertices ; j++){
            scanf("%d",&adj[i][j]);
        }
    }
    vector<vector<long long int>> distances(n_vertices);
    for(int i = 0; i< n_vertices; i++){
        distances[i].resize(n_vertices);
        for(int j = 0; j< n_vertices; j++){
            if (i!=j){
                distances[i][j] = inf;
            }
            else{
                distances[i][j] = 0;
            }
        }
    }
    vector<int> toBeRemoved(n_vertices);
    vector<int> alive(n_vertices);
    for(int i = 0; i< n_vertices; i++){
        scanf("%d",&toBeRemoved[n_vertices-i-1]);
        toBeRemoved[n_vertices-i-1]--;
    }
    for(int z = 0; z< n_vertices ; z++){
        int x = toBeRemoved[z];
        alive[x] = 1;
        for(int i = 0; i< n_vertices; i++){
            if (alive[i] == 1){
                distances[i][x] = adj[i][x];
                distances[x][i] = adj[x][i];
            }
        }
        for(int i = 0; i< n_vertices; i++){
            for(int j = 0; j< n_vertices; j++){
                distances[x][i]=min(distances[x][i],distances[x][j]+distances[j][i]);
                distances[i][x]=min(distances[i][x],distances[i][j]+distances[j][x]);
            }
        }
        for(int i = 0; i< n_vertices; i++){
            for(int j = 0; j< n_vertices; j++){
                distances[i][j]=min(distances[i][j],distances[i][x]+distances[x][j]);
            }
        }
        long long sum = 0;
        for(int i = 0; i< n_vertices; i++){
            for(int j = 0; j< n_vertices; j++) {
                if (alive[i]==1 && alive[j]==1){
                    sum+=distances[i][j];
                }
            }
        }
        ans[z] = sum;
    }

    for(int i = n_vertices-1; i>=0; i--){
        printf("%I64d ", ans[i]);
    }
    printf("\n");


    return 0;

}