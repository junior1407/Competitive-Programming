// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/problemset/problem/1132/B


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int a,b;
    scanf("%d",&n);
    vector<long int> arr(n);
    long int sum = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%ld",&arr[i]);
        sum+= arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    int n_coupons,x;
    scanf("%d",&n_coupons);
    for(int i = 0; i<n_coupons; i++){
        scanf("%d",&x);
        printf("%ld\n", sum - arr[x-1]);
    }
    return 0;
}