// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1358/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n, &m);
        printf("%d\n", (n*m +1)/2);
    }
}
