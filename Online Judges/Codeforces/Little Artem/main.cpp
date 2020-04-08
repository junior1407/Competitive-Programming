// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1333/problem/A

#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                printf("%c", i==1 && j==1? 'W': 'B');
            }
            printf("\n");
        }
    }
    return 0;
}
