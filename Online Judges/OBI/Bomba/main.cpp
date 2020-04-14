// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://olimpiada.ic.unicamp.br/pratique/p2/2012/f2/bomba/


#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ii pair<int,int>
map<int, vector<ii>> graph;
int djikstra(int start, int destiny, int vertices){
    vector<vector<int>> visited (vertices);
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.push({0,start}); // (curr_time, curr_vertex)
    int u, currTime;
    int v, t;
    while(!pq.empty()){
        currTime = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (u == destiny){
            return currTime;
        }
        if (find(visited[u].begin(), visited[u].end(),currTime%3)!=visited[u].end()){
            // if was already visited in this currTime%3, skip
            continue;
        }
        visited[u].push_back(currTime%3);

        for(auto item: graph[u]){
            v = item.first;
            t = item.second;  // t== 1 is open only time%3 ==0.  t == 0 is open time%3!=0
            if ((t == 1 && currTime%3 == 0) || (t == 0 && currTime%3!=0)){
                pq.push({currTime+1, v});
            }
        }
    }
    return -1;
}
int main(){
    int vertices,  start, destiny,  edges;
    scanf("%d %d %d %d",&vertices, &start, &destiny, &edges);
    int u,v, t;
    for(int i = 0; i< edges; i++){
        scanf("%d %d %d",&u,&v,&t);
        graph[u].push_back({v,t});
    }
    int x = djikstra(start, destiny, vertices);
    if (x== -1){
        printf("*\n");
    }else{
        printf("%d\n", x);
    }
    return 0;
}