// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1342/problem/C


#include <bits/stdc++.h>
using namespace std;
const int N = 40043;
int dp[N];

int a,b;
long long query(long long l){
    long long segment = l / (a*b);
    int remainder = l % (a*b);
    return dp[a*b]* 1LL  * segment + dp[remainder];

}

long long query(long long l, long long r){
    return query(r) - query(l-1);
}

int main() {
    int t, q;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d",&a,&b,&q);
        dp[0] = 0;
        for(int i = 1; i<=a*b; i++){
            dp[i] = dp[i-1];
            if((i % a) % b != (i % b) % a){
                dp[i]++;
            }
        }
        long long l,r;
        for(int i = 0; i < q; i++){
            cin >> l >> r;
            cout << query(l,r) << " ";
        }
        printf("\n");

    }
    return 0;
}