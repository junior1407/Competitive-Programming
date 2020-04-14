// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1409


#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define llii pair<long long int, int>
vector<long long int> monsters;
map<int, vector<int>> graph;
vector<long long int> dp;

void DP(vector<ii>& magics){
    // (mana, dmg)
    dp[0] = 0;
    long long currentMana;
    for(int i = 1 ; i <=1000 ; i++){
        for(int j = 0 ; j < magics.size(); j++){
            if (j == 0){
                dp[i] = magics[j].first+ dp[max(i-magics[j].second,0)];
            }else{
                dp[i] = min(dp[i], magics[j].first+ dp[max(i-magics[j].second,0)]);
            }
        }
    }
}
long long int djikstra(int start, int end){


    priority_queue<llii, vector<llii>, greater<llii>> pq;
    pq.push({monsters[start], start});
    map<int, int> visited = {};
    long long int currMana;
    int u;
    while(!pq.empty()){

        currMana = pq.top().first;
        u= pq.top().second;
        pq.pop();
        if (visited.find(u) != visited.end()){

            continue;
        }
        visited[u] = 1;
        if (u == end){
            return currMana;
        }
        for(auto v: graph[u]){



            if (visited.find(v) == visited.end()){

                pq.push({currMana+monsters[v], v});
            }
        }
    }

    return -1;
}

int main(){
    int x, y;
    int n_magics, n_vertex,  n_edges,  n_monsters;
    while(true){
        scanf("%d %d %d %d", &n_magics, &n_vertex, &n_edges, &n_monsters);
        if (n_magics == 0 && n_vertex == 0 && n_edges == 0 && n_monsters == 0){
            break;
        }
        dp.clear();
        monsters.clear();
        graph.clear();
        dp.resize(1001);
        monsters.resize(n_vertex+1);

        vector<ii> magics (n_magics);  // (mana, dmg)

        for(int i = 0 ; i< n_magics; i++){
            scanf("%d %d", &x,&y);
            magics[i] = { x, y};
        }
        for(int i = 0; i< n_edges; i++){
            scanf("%d %d", &x,&y);
            x--;
            y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        DP(magics);

        for(int i = 0; i< n_monsters; i++){
            scanf("%d %d", &x,&y);
            x--;
            monsters[x]+= dp[y];
        }
        printf("%lld\n",djikstra(0, n_vertex-1));

    }


    return 0;
}