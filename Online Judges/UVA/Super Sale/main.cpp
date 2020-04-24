// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1071


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int dp[31] = {0};
        int p, w;
        for(int i = 0; i< n; i++){
            scanf("%d %d", &p, &w);
            for(int j = 30; j >= w; j--){
                if (dp[j] < dp[j-w] + p){
                    dp[j] =  dp[j-w] + p;
                }
            }
        }

        int g, x;
        scanf("%d", &g);
        int soma = 0;
        for(int i = 0; i<g; i++){
            scanf("%d", &x);
            soma+=dp[x];
        }
        printf("%d\n", soma);
    }

    return 0;
}