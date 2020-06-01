// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1363/problem/A


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x, temp, even, odd;
    scanf("%d",&t);
    while(t--){
        even = 0;
        odd = 0;
        scanf("%d %d",&n,&x);
        while(n--){
            scanf("%d",&temp);
            if (temp % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        // case we can use all even
        x -=  min(x-1, even);
        if (x % 2 == 1&& odd>=x){
            printf("Yes\n");
        }
            // case where we need to form some even with odds
        else if (odd > x  && even >=1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }
}
