// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/coin-change
#include <bits/stdc++.h>
using namespace std;
int value, n_coins;
vector<int> coins;
map<pair<int, int>, long long> hashuh;
long long DP(int remaining, int curr_coin){
    if (curr_coin>= n_coins){
        return 0;
    }
    if (remaining == 0){
        return 1;
    }
    auto it = hashuh.find(make_pair(remaining, curr_coin));
    if (it != hashuh.end()){
        return it->second;
    }
    int quocient = remaining / coins[curr_coin];
    int remainder = remaining % coins[curr_coin];
    if (curr_coin + 1 == n_coins){
        if (remainder == 0){
            hashuh[make_pair(remaining,curr_coin)] =1;
            return 1;
        }
        hashuh[make_pair(remaining,curr_coin)] =0;
        return 0;
    }
    remainder = remaining;
    long long counter = 0;
    for (int i = 0 ; i<= quocient;i++ ){
        if (i!=0){
            remainder = remaining  - (i * coins[curr_coin]);
        }
        long long retorno = DP(remainder, curr_coin+1);
        counter +=  retorno;
    }
    hashuh[make_pair(remaining,curr_coin)] =counter;
    return counter;
}

int main() {
    scanf("%d %d",&value, &n_coins);
    coins.resize(n_coins);
    for (int i = 0 ; i< n_coins; i++){
        scanf("%d",&coins[i]);
    }
    sort(coins.begin(), coins.end());
    reverse(coins.begin(), coins.end());
    printf("%lld\n", DP(value, 0));

    return 0;
}
