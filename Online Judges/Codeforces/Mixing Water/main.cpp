// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1359/problem/C


#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long hot, cold, desired;
        scanf("%lld %lld %lld",&hot,&cold, &desired);
        if (desired*2 <= hot+cold){
            printf("2\n");
            continue;
        }
        //always k hot and k-1 cold.
        ll left = 1;
        ll right = 1e11;
        while(left < right){
            ll middle = (left+right)/2;
            ll k = middle;
            // printf("%lld <= %lld\n",((k - 1) * cold + k * hot), desired * (2 * k - 1) );
            if (((k - 1) * cold + k * hot) <= desired * (2 * k - 1)) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        if (left == 1){
            printf("1\n");
        }
        else{
            ll k = left;
            ll A = 2 * k - 1;
            ll B = 2 * (k - 1) - 1;
            if (2 * desired * A * B < ((k - 1) * cold + k * hot) * B + ((k - 2) * cold + (k - 1) * hot) * A) {
                cout << 2 * k - 1 << '\n';

            }
            else {
                cout << 2 * (k - 1) - 1 << '\n';
                // we need need 1 less.
            }
        }
        //   printf("%lld %lld", left, right);

    }
    return 0;
}