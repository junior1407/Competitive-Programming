// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1931

#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ii pair<int,int>
map<int, vector<ii>> graph;

vector<ii> distances; // (par, impar)
int vertices, edges;

void djikstra(){
    distances[0].first = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;  // (curr_cost,  curr_vertex)
    pq.push({0, 0});
    int  u, v, w;
    while(!pq.empty()){
        u=pq.top().second;
        pq.pop();
        for (auto item:  graph[u]){
            v = item.first;
            w = item.second;

            if (distances[v].first > distances[u].second + w){
                distances[v].first = distances[u].second + w;
                pq.push({distances[v].first, v});
            }
            if (distances[v].second > distances[u].first + w){
                distances[v].second = distances[u].first + w;
                pq.push({distances[v].second, v});
            }
        }
    }

}
int main(){

    scanf("%d %d",&vertices,&edges);
    int u,v,c;
    for(int i = 0; i< edges; i++){
        scanf("%d %d %d",&u,&v, &c);u --;v --;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    distances.resize(vertices);
    for(int i = 0; i< vertices; i++){
        distances[i].first = inf;distances[i].second = inf;
    }
    djikstra();
    if (distances[vertices-1].first != inf){
        printf("%d\n", distances[vertices-1].first);
    }else{
        printf("-1\n");
    }
    return 0;
}