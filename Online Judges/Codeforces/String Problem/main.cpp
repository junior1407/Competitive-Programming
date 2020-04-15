// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/33/problem/B


#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
#define n_nodes (int) ('z'-'a'+1)

vector<vector<long long int>> distances(n_nodes);
map<int, map<int, int>> graph;

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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (s1.length() == s2.length()){
        long long ans=0;
        int n_edges;
        scanf("%d",&n_edges);
        int c;
        char u_c, v_c;
        getchar();
        int i, j;
        while(n_edges --){
            scanf("%c %c %d",&u_c,&v_c,&c);getchar();
            //  printf("%c %c %d\n", u_c, v_c, c);
            i = (int)u_c - 97;
            j = (int)v_c - 97;
            if (graph.find(i) != graph.end()){
                if (graph[i].find(j) != graph[i].end()){
                    graph[i][j] = min(graph[i][j], c);
                }
                else{
                    graph[i][j] = c;
                }
            }
            else{
                graph[i][j] = c;
            }

        }
        floyd();
        int a, b;
        for(int i = 0; i< s1.length(); i++){
            if (s1[i] != s2[i]){
                a = s1[i];
                b = s2[i];
                a-='a';
                b-='a';
                int best_index;
                long long best_sum;
                for(int j = 0; j<='z'-'a'; j++){
                    if (j==0){
                        best_index = j;
                        best_sum = distances[a][j] + distances[b][j];
                    }
                    else{
                        if (best_sum > distances[a][j] + distances[b][j]){
                            best_index = j;
                            best_sum = distances[a][j] + distances[b][j];
                        }
                    }
                }
                if (best_sum>=inf){
                    printf("-1\n");
                    return 0;
                }

                s1[i] = (char) (best_index + 97);
                s2[i] = s1[i];
                ans+=best_sum;

            }
        }
        printf("%lld\n",ans);
        cout << s1;


    }
    else{
        printf("-1\n");
    }
    return 0;

}