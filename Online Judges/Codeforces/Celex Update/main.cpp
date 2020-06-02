// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1358/problem/C


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long x1, y1,x2,y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        printf("%lld\n", (x2-x1)*(y2-y1) +1);
    }
}