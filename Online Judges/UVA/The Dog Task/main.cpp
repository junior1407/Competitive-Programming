// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=611

#include <bits/stdc++.h>
using namespace std;

// source -> all master positions -> interesting -> target
int masterCoords[100][2]; // (x,y)
int interCoords[100][2]; // (x,y)
int n_master, n_inter;
map<int, map<int, int>> graph;

int n_vertices;

void addEdge(int u, int v, int f){
    graph[u][v] = f;
    graph[v][u] = 0;
}

bool BFS(int source, int target, vector<int>& prev, int &min_flow){
    vector<int> visited(n_vertices);
    prev.clear();
    min_flow = INT_MAX;
    visited[0] = 1;
    queue<int> q;
    prev[0] = 0;
    q.push(0);
    int u, v, f;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if (u == target){
            return true;
        }
        for(auto it = graph[u].begin(); it!= graph[u].end(); it++){
            v = it->first;
            f = it->second;
            if (graph.count(u) == 1){
                if (graph[u].count(v) == 1){
                    if (graph[u][v]>0){
                        if (visited[v]==0) {
                            visited[v] = 1;
                            min_flow = min(min_flow, f);
                            prev[v] = u;
                            q.push(v);
                        }
                    }
                }
            }

        }
    }
    return false;
}

int fk(int source, int target){
    vector<int> prev(n_vertices);
    int min_flow;
    int max_flow = 0;
    while(BFS(source, target, prev, min_flow)){
        int v = target;
        int u;
        max_flow+= min_flow;
        while(v != source){
            u = prev[v];
            graph[u][v] -= min_flow;
            graph[v][u] += min_flow;
            v = u;
        }
    }
    return max_flow;

}


void printPath(int target){
    map<int, int> to; // from master[i] to inters[j];

    //by checking the backflow, we can see what decision were made. I`m saving on a map so i can print them later.
    for(auto it=  graph[target].begin(); it != graph[target].end(); it++){
        if (it->second == 1){
            for(auto it2=  graph[it->first].begin(); it2 != graph[it->first].end(); it2++){
                if(it2->second == 1){
                    to[it2->first -1] = it->first - n_master - 1;
                }
            }
        }
    }
    int intere;
    for(int i = 0; i< n_master; i++){
        printf("%d %d", masterCoords[i][0], masterCoords[i][1]);
        if (to.count(i) == 1){
            intere = to[i];
            printf(" %d %d", interCoords[intere][0], interCoords[intere][1] );
        }
        if (i+1 == n_master){
            printf("\n");
        }else{
            printf(" ");
        }

    }

}
double Distance(int A[], int B[]){
    return(sqrt(pow(A[0] - B[0], 2) + pow(A[1] - B[1], 2)));
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        graph.clear();
        scanf("%d %d", &n_master, &n_inter);
        for(int i = 0; i < n_master; i++){
            scanf("%d %d",&masterCoords[i][0],&masterCoords[i][1]);
        }
        for(int i = 0; i < n_inter; i++){
            scanf("%d %d",&interCoords[i][0],&interCoords[i][1]);
        }

        int source = 0;
        // masters = 1 to n
        // interest  = n+1 to m+n
        int target = n_master+n_inter+1;
        n_vertices = target+1;

        // from source to all masters (except the last)
        for(int i = 0; i< n_master-1;i++){
            addEdge(0,i+1,1);
        }
        // from interesting to target
        for(int i =0 ; i< n_inter; i++){
            addEdge(n_master+1+i,target,1);
        }

        //from all masters (except the last) to all interesiting points if the distance is possible.
        for(int i =0 ; i< n_master -1; i++){
            //     printf("Checking master %d\n", i+1);
            double distanceNextMaster = Distance(masterCoords[i], masterCoords[i+1]);
            for(int j = 0; j<n_inter ; j++){
                double distanceInter = Distance(masterCoords[i], interCoords[j]) + Distance(interCoords[j], masterCoords[i+1]);
                if (distanceInter <= distanceNextMaster*2){
                    //     printf("from %d to %d is possible\n", i+1, n_master+1+j );
                    addEdge(i+1, n_master+1+j, 1);
                }
            }
        }
        printf("%d\n", fk(0, target) + n_master);
        printPath(target);
        if (t>0){
            printf("\n");
        }
    }
    return 0;
}