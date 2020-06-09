// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1359/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int n_cards_player = n/k;
        int a1 = min(m,n_cards_player);
        int remainingJokers = m  - a1;
        int a2 = (remainingJokers + k - 2)/(k-1);
        printf("%d\n",a1-a2);
    }

    return 0;
}