// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://olimpiada.ic.unicamp.br/pratique/p2/2012/f1/tarzan/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
map<int, vector<int>> graph;
int n,d;

float distance(ii a, ii b){
    float x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)* (y2-y1));
}

void dfs(vector<int>& visited, int& visited_counter,  int curr){
    if (visited[curr] == 1){
        return;
    }
    //printf("Visiting curr=%d\n", curr);
    visited[curr] = 1;
    visited_counter++;
    if (visited_counter == n){
        return ;
    }
    for(auto it: graph[curr]){
        if (visited[it] == 0){
            dfs(visited, visited_counter, it);
        }
    }


}

int main() {

    scanf("%d %d",&n, &d);
    vector<ii> trees(n);
    int x,y;
    for(int i = 0; i< n; i++){
        scanf("%d %d",&x, &y);
        trees[i] = {x,y};
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j< n ; j++){
            if (i!=j){
                if (distance(trees[i], trees[j]) <= (float) d){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
    vector<int> visited(n);
    int visited_counter = 0;
    dfs(visited, visited_counter, 0);
    if (visited_counter == n){
        printf("S\n");
    }else{
        printf("N\n");
    }
    return 0;
}