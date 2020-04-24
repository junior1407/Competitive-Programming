// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.thehuxley.com/problem/874

#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int dp(int n, vector<int>& prices){
    if (memo.count(n) >= 1){
        return memo[n];
    }
    if (n==1){
        memo[n] = prices[1];
        return memo[n];
    }
    int i = n-1;
    int j = 1;
    int best = prices[n];
    while(i>=1){
        best = max(best, prices[i] + dp(j, prices));
        i--;
        j++;
    }
    memo[n] = best;
    return best;
}

int main(){
    int n;
    while(true){
        memo.clear();
        scanf("%d",&n);
        if (n ==0){
            break;
        }
        vector<int> prices(n+1);
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&prices[i]);
        }
        printf("%d\n", dp(n, prices));
    }
    return 0;
}