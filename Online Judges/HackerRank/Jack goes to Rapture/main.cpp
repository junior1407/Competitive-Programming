// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/jack-goes-to-rapture/problem


#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define inf 1e9
map<int, vector<ii>> graph;
int nodes, edges;

int dijkstra(int origin, int end){
    vector<int> visited(nodes);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,0});
    int u, v, w, currDistance;
    while(!pq.empty()){
        currDistance = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (visited[u] == 1){
            continue;
        }
        visited[u] = 1;
        if (u == end){
            return currDistance;
        }
        for(auto it:  graph[u]){
            v = it.first;
            w = it.second;
            if (visited[v] == 0){
                pq.push({max(currDistance, w), v});
            }
        }
    }
    return -1;

}
int main(){

    scanf("%d %d",&nodes, &edges);
    int u, v, w;
    for(int i = 0; i< edges; i++){
        scanf("%d %d %d",&u, &v, &w);
        u--;v--;
        if (w < 0){
            w = 0;
        }
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int result = dijkstra(0, nodes-1);
    if (result == -1){
        printf("NO PATH EXISTS\n");
    }
    else{
        printf("%d\n", result);
    }


}