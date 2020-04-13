// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1409


#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
map<int, vector<int>> monsters;
map<int, vector<int>> graph;
vector<long long int> dp(1000);

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

int main(){
    int x, y;
    int n_magics, n_vertex,  n_edges,  n_monsters;
    while(scanf("%d %d %d %d", &n_magics, &n_vertex, &n_edges, &n_monsters) != EOF){
        if (n_magics == 0 && n_vertex == 0 && n_edges == 0 && n_monsters == 0){
            return 0;
        }
        vector<ii> magics (n_magics);  // (mana, dmg)
        for(int i = 0 ; i< n_magics; i++){
            scanf("%d %d", &x,&y);
            magics[i] = { x, y};
        }
        for(int i = 0; i< n_edges; i++){
            scanf("%d %d", &x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        DP(magics);
        for(int i = 0; i< n_monsters; i++){
            scanf("%d %d", &x,&y);
            monsters[x].push_back(y);
        }

    }


    return 0;
}