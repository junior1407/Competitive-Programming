// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1337/problem/C

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, k, depth[N],counter[N];
vector<int> graph[N];
vector<pair<int, int>> vec;
void dfs(int v,  int parent){
    for(auto u: graph[v]){
        
        if (u == parent){
            continue;
        }
        depth[u] = depth[v] + 1;
        dfs(u, v);
        counter[v]+= counter[u];
    }
    vec.push_back({depth[v]-counter[v], v});
    counter[v]++;
}

int main(){
    scanf("%d %d",&n, &k);
    int u, v;
    for(int i = 0 ; i < n-1 ; i++){
        scanf("%d %d",&u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,1);

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    long long ans = 0;
    for(int i = 0; i < k; i++)
        ans += vec[i].first;
    cout << ans << "\n";
}
