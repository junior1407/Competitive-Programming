// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1354/problem/A


#include "bits/stdc++.h"
using namespace std;


int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b,c,d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        //he has enough time to sleep
        if (b>=a){
            printf("%d\n",b);
            continue;
        }
        // if he can`t  fall sleep before the alarm rings
        if (c<=d){
            printf("-1\n");
            continue;
        }
        long long sleeps_per_session = c-d;
        printf("%lld\n", b + (a-b + sleeps_per_session - 1)/sleeps_per_session* c);
    }
    return 0;
}