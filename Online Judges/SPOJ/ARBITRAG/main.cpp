// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.spoj.com/problems/ARBITRAG/


#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> distances;
map<string, int> translate;

map<int, map<int, double>> graph;


int n_nodes;
void prepareDistances(){
    distances.resize(n_nodes);
    for(int i = 0 ; i< n_nodes; i++){
        distances[i].resize(n_nodes);
        for(int j = 0 ; j < n_nodes; j++){
            distances[i][j] = 0;
            if (graph.find(i) != graph.end()){
                if (graph[i].find(j) != graph[i].end()){
                    distances[i][j] = graph[i][j];
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
                if (distances[i][j] < distances[i][k] * distances[k][j]){
                    distances[i][j] = distances[i][k] * distances[k][j];
                }
            }

        }
    }

}



int main(){
    int cases = 1;
    int n_edges;
    string a, b, c;
    double x;
    scanf("%d",&n_nodes);
    while(n_nodes!=0){
        translate.clear();
        for(int i = 0 ; i< n_nodes; i++){
            cin >> a;
            translate[a] =i;
        }
        scanf("%d",&n_edges);
        while(n_edges--){
            cin >> a >> x >> b;
            graph[translate[a]][translate[b]] = x;
        }
        floyd();
        int i;
        for(i = 0; i< n_nodes; i++){
            if (distances[i][i]> 1.0){
                break;
            }
        }
        printf("Case %d: ", cases);
        if (i == n_nodes) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        cases++;

        scanf("%d",&n_nodes);
    }

    return 0;

}