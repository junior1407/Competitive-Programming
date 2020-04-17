// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerearth.com/pt-br/practice/algorithms/graphs/minimum-cost-maximum-flow/practice-problems/algorithm/amazing-race-3/


#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define inf 1e18
const int maxSize = 200 + 200 + 2 + 1;
lli matrixGraph[maxSize][maxSize][2]; // [u][v] = (flow, cost)
vector<vector<int>> graph;
int n_teams, n_checkpoints, n_winners;

// 0      -> 1 to n_teams -> (n) +
// source -> team (n) -> check (m) -> target1 -> target2
void addEdge(int u, int v, int f, int c){
    graph[u].push_back(v);
    matrixGraph[u][v][0] = f; matrixGraph[u][v][1] = c;
    graph[v].push_back(u);
    matrixGraph[v][u][0] = 0; matrixGraph[v][u][1] = -c;
}

double distance(        int pointA[], int pointB[], double speed){
    double x_1 = pointA[0], y_1 = pointA[1], x_2 = pointB[0], y_2 = pointB[1];
    return(ceil(((x_2-x_1)*(x_2-x_1) + (y_2-y_1)*(y_2-y_1)) / (speed * speed)));
}

bool bellmannFord(int prev[], int source, int target){
    //   printf("--------------------------------------\n");
    lli cost[maxSize];
    for(int i = 0; i< maxSize; i++){
        cost[i] = inf;
    }
    cost[0] = 0;
    for(int i = 0; i< n_teams+n_checkpoints+2 + 1 - 1;  i++){
        int hasChanged = 0;
        for(int u = 0; u < n_teams+n_checkpoints+2 + 1; u++){
            for(auto v: graph[u]){
                if (matrixGraph[u][v][0]>0 &&  max(cost[u], matrixGraph[u][v][1]) < cost[v]){
                    cost[v] = max(cost[u], matrixGraph[u][v][1]);
                    prev[v] = u;
                    hasChanged=1;
                }
            }
        }
        if (hasChanged == 0){
            break;
        }
    }
    return cost[target] < inf;

}
void minCostFlow(lli& maxFlow, lli&minCost, int source, int target){
    int prev[maxSize];
    while(bellmannFord(prev, source, target)){
        int v = target;
        lli flow = inf, cost =0;
        while(v!= source){
            flow = min(flow, matrixGraph[prev[v]][v][0]);
            cost = max(cost, matrixGraph[prev[v]][v][1]);
            v= prev[v];
        }
        maxFlow+=flow;
        minCost = max(minCost, cost);
        v = target;
        while(v!= source){
            matrixGraph[prev[v]][v][0] -= flow;
            matrixGraph[v][prev[v]][0] +=flow;
            v= prev[v];
        }
    }
}

int main(){

    scanf("%d %d %d", &n_teams, &n_checkpoints, &n_winners);
    int teamPos[n_teams][2], checkPos[n_checkpoints][2], speeds[n_teams];
    for(int i = 0; i< n_teams; i++){
        scanf("%d %d",&teamPos[i][0], &teamPos[i][1]);
    }
    for(int i = 0; i< n_checkpoints; i++){
        scanf("%d %d",&checkPos[i][0], &checkPos[i][1]);
    }
    for(int i = 0; i< n_teams; i++){
        scanf("%d",&speeds[i]);
    }
    graph.resize(n_teams+n_checkpoints+1+2);

    // linking source(0) to all teams with flow 1, cost 0.
    for(int i = 1; i<= n_teams; i++){
        addEdge(0, i, 1, 0);
    }

    for(int i = 0; i < n_checkpoints; i++){ //linking all checkpoints to TARGET1
        addEdge(n_teams+i+1, n_teams+n_checkpoints+1, 1, 0);
    }
    for(int i = 0; i < n_teams; i++){ // ; linking all teams to all checkpoints
        for(int j = 0; j<n_checkpoints; j++){
            addEdge(i+1, j+n_teams+1, 1, distance(teamPos[i], checkPos[j], speeds[i]));
        }
    }

    //linking target1 to target 2
    addEdge(n_teams+n_checkpoints+1,n_teams+n_checkpoints+2, n_winners, 0);

    lli maxflow = 0, minCost = 0;
    minCostFlow(maxflow, minCost, 0, n_checkpoints+n_teams+2);
    printf("%lld\n", minCost);


    return 0;

}