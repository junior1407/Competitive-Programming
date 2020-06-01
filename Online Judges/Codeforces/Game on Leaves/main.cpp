// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1363/problem/C

#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    int u, v, n , x;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &x);
        vector<int> deg(n+2);
        for(int i = 0; i < n -1 ; i++){
            scanf("%d %d", &u, &v);
            deg[u]++;
            deg[v]++;
        }
        if (deg[x] <= 1){
            printf("Ayush\n");
        }
        else{
            if (n %2 == 0){
                printf("Ayush\n");
            }
            else{
                printf("Ashish\n");
            }
        }
    }
}
