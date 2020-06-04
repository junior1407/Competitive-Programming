// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1348/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        //the last one with (n/2 - 1)
        int sum1 = 1 << n;
        for(int i =1; i < n/2; i++){
            sum1+= 1 << i;
        }
        // the rest
        int sum2 = 0;
        for(int i = n/2; i < n; i++){
            sum2+=1<<i;
        }
        printf("%d\n", sum1-sum2);
    }
}