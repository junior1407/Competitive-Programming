// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/problemset/problem/1296/D


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b,k;
    scanf("%d %d %d %d",&n, &a,&b,&k);
    vector<int> costs(n);
    int x;
    int division, remainder;
    for(int z = 0; z < n; z++){
        scanf("%d",&x);
        //  printf("monstro %d remainder %d divison %d remainder %d ", x,x % (a+b), (x % (a+b)/a), (x % (a+b)%a));
        x = x % (a+b);
        if (x==0){
            x = a+b;
        }
        //remainingLife - a * (noTurns) <= 0
        division = x /a;
        remainder = x % a;
        if (remainder > 0){
            costs[z] = division;
        }
        else{
            costs[z] = division -1;
        }
    }
    sort(costs.begin(), costs.end());
    int points = 0;
    for(int i = 0; i< n;  i++){
        if (costs[i] <= k){
            points++;
            k -= costs[i];
        }
    }
    printf("%d\n", points);
    return 0;
}