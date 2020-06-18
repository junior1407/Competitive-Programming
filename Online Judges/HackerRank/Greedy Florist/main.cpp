// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/greedy-florist/problem

#include <bits/stdc++.h>
using namespace std;

int solve(int k, int n, vector<int>& prices){

    int cost = 0;
    sort(prices.begin(), prices.end());
    if (k >= n){
        for(int i = 0; i < n; i++){
            cost+= prices[i];
        }
    }
    else{
        int j = 0;
        int cycles = 0;
        for(int i = n-1; i >= 0 ; i--){
            if (j == k){
                j = 0;
                cycles++;
            }
            cost+= (cycles + 1) * prices[i];
            j++;
        }
    }
    return cost;
}

int main(){

    int n, k;
    scanf("%d %d",&n,&k);
    vector<int> prices(n);
    for(int i = 0; i< n; i++){
        scanf("%d",&prices[i]);
    }
    int ans = solve(k, n, prices);

    printf("%d\n", ans);
    return 0;
}