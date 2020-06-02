// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1363/problem/E

#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define pii pair<lli,lli>
const int inf =  2e5+5;


vector<int> adjacencies[inf];
vector<long long> cost, is, target;
long long ans = 0;
pii dfs(int u, int prev, long long& parent_cost){
    // printf("Am at %d\n", u);
    int wants1 = 0;
    int wants0 = 0;
    if (is[u] != target[u]){
        wants1 += target[u] == 1;
        wants0 += target[u] == 0;
    }
    pii a = {wants1, wants0};
    for (auto it: adjacencies[u]) {
        if (it == prev) {
            continue;
        }
        long long temp = min(parent_cost, cost[u]);
        pii b = dfs(it, u, temp);
        a.first += b.first;
        a.second += b.second;

    }
    if (cost[u] < parent_cost){
        int changed = min(a.first, a.second);
        ans += 2 * changed * cost[u];
        a.first -= changed;
        a.second-=changed;
    }
    return a;
}

int main(){
    int n, u,v;
    scanf("%d",&n);
    cost.resize(n+1);
    is.resize(n+1);
    target.resize(n+1);
    for(int i =1; i<= n; i++) {
        scanf("%lld %lld %lld",&cost[i], &is[i], &target[i]);
    }

    for(int i = 1; i<= n-1; i++){
        scanf("%d %d",&u, &v);
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }
    long long int temp = 2e9;
    pii a = dfs(1, 0, temp);
    if (a.first == 0 & a.second == 0){
        printf("%lld\n",ans);
    }
    else{
        printf("-1\n");
    }

    return 0;
}