// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1345/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d %d",&n,&m);
        if (n == 1 || m == 1 || (n==2&&m==2)){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;

}