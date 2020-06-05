// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1345/problem/B

#include<bits/stdc++.h>
using namespace std;
#define lli long long
int main() {
    lli t;
    scanf("%lld",&t);
    while (t--) {
        lli x;
        scanf("%lld",&x);
        lli res = 0;
        for (lli n = 3e4; n >= 1; n--) {
            lli k = 3*n*(n+1)/2 - n;
            res += x/k;
            x %= k;
        }
        printf("%lld\n",res);
    }
}