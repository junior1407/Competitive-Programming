// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1364/problem/A


#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int arr[maxN];
int main(){
    int t;
    int n, x;
    long sum = 0;
    scanf("%d",&t);
    while(t--){
        sum = 0;
        scanf("%d %d",&n, &x);
        for(int i = 0; i< n; i++){
            scanf("%d",&arr[i]);
            sum+= arr[i];
        }
        int p1 = 0, p2;
        if (sum % x != 0){
            printf("%d\n", n);
            continue;
        }
        while(p1 < n && (arr[p1] % x == 0)){
            p1++;
        }
        if (p1 == n){
            printf("-1\n");
            continue;
        }
        p2  = n-1;
        while(arr[p2] % x == 0){
            p2--;
        }
        printf("%d\n", max(n-p1-1, p2));

    }


}
