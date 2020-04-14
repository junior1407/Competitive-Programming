// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem

#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

map<int, map<int, int>> graph;
int n_nodes, n_edges;
vector<vector<int>> distances;


void prepareDistances(){
    distances.resize(n_nodes);
    for(int i = 0 ; i< n_nodes; i++){
        distances[i].resize(n_nodes);
        for(int j = 0 ; j < n_nodes; j++){
            distances[i][j] = inf;
            if (i == j){
                distances[i][j] = 0;
            }else{
                if (graph.find(i) != graph.end()){
                    if (graph[i].find(j) != graph[i].end()){
                        distances[i][j] = graph[i][j];
                    }
                }
            }


        }
    }
}

void floyd(){

    prepareDistances();
    for(int k = 0; k< n_nodes; k++){
        for(int i = 0; i< n_nodes; i++){
            for(int j = 0; j< n_nodes; j++){
                if (distances[i][j] > distances[i][k] + distances[k][j]){
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }

        }
    }

}
int main(){
    scanf("%d %d",&n_nodes, &n_edges);
    int u,v,c;
    for(int i = 0; i< n_edges; i++){
        scanf("%d %d %d",&u,&v, &c);
        u--;
        v--;
        graph[u][v] =c;
    }
    floyd();
    int q;
    scanf("%d",&q);
    int ans;
    while(q--){
        scanf("%d %d",&u,&v);
        u--;v--;
        ans = distances[u][v];
        if (ans == inf){
            printf("%d\n", -1);
        }
        else{
            printf("%d\n", distances[u][v]);
        }

    }
    return 0;
}