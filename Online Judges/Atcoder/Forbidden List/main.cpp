// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://atcoder.jp/contests/abc170/tasks/abc170_c

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n, temp;
    int found[103] = {0};  // 0 means -1.  So +1 in everything.
    scanf("%d %d", &x, &n);
    for(int i = 0; i<n; i++){
        scanf("%d",&temp);
        found[temp+1] = 1;
    }
    int best_number = int(1e4);
    int best_difference = int(1e4);
    for(int i = -1; i <=101 ; i++){
        if (found[i+1] == 0) {
            if ( abs(i -x) < best_difference){
                best_difference = abs(i -x);
                best_number = i;
            }
        }
    }
    printf("%d\n", best_number);

    return 0;
}