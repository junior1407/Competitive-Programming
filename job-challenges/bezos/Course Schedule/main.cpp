#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>


int top(int n, vvi& requisites) {
    int visited_counter = 0;
    vvi graph_requisites(n), back_graph(n);
    vi indegree(n);
    // [calc2, calc1]
    for (auto it : requisites) {
        graph_requisites[it[0]].push_back(it[1]);
        back_graph[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }
    stack<int> stc;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stc.push(i);
        }
    }
    vector<int> sorted;
    vector<int> visited(n);
    while (!stc.empty()) {
        int u = stc.top(); stc.pop(); visited[u] = 1;
        counter++; sorted.push_back(u); 
        for (auto v : back_graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                stc.push(v);
            }
        }
    }
    printf("PRINTING SORTED\n");
    for(int i = 0; i < sorted.size(); i++) {
        printf("%d\n", sorted[i]);
    }
    return sorted.size();

}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.size() == 0) {
        return true;
    }
    return top(numCourses, prerequisites) == numCourses;
}

int main() {
    vvi case1 = {{0,1}, {2,0}, {2,3}};
    if (canFinish(5, case1)) {
        printf("Sucess");
    }
    else {
        printf("Failed");
    }
    printf("\n");


    vvi case2 = {{1,0}, {0,1}};
    if (canFinish(2, case2) == false) {
        printf("Sucess");
    }
    else {
        printf("Failed");
    }
    printf("\n");
    return 0;
}