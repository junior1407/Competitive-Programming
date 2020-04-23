// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.urionlinejudge.com.br/judge/pt/problems/view/2666

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
map<int, vector<ii>> graph;

void addEdge(int u, int v, int c){
    graph[u].push_back({v,c});
    graph[v].push_back({u,c});
}

ii bfs(int c, vector<int>& debt, int curr,  int origin){
    int curr_distance = 0;
    int curr_gold = debt[curr];
    int v, w;
    for(auto it: graph[curr]){
        v = it.first; w = it.second;
        if (v!= origin){
            ii gold_distance =  bfs(c, debt, v, curr);
            int gold = gold_distance.first, distance = gold_distance.second;
            curr_distance+=distance;
            curr_gold+=gold;
            int trips = gold/c;
            if (gold % c != 0){
                trips++;
            }
            curr_distance += 2 * trips * w;
        }
    }
    return {curr_gold, curr_distance};
}

int main(){

    int n, c;
    scanf("%d %d",&n, &c);
    vector<int> debt(n);
    for(int i = 0; i< n; i++){
        scanf("%d",&debt[i]);
    }
    int u,v,w;
    for(int i = 0; i< n-1; i++){
        scanf("%d %d %d",&u,&v, &w);
        u--; v--;
        addEdge(u,v,w);
    }
    printf("%d\n", bfs(c, debt, 0,0).second);
}