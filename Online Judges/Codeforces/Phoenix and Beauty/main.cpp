// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1348/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d",&n,&k);
        set<int> s;
        for(int i = 0; i<n; i++){
            int a;
            scanf("%d",&a);
            s.insert(a);
        }
        if (s.size() > k){ // we need to have periods of k.
            printf("-1\n");
            continue;
        }
        printf("%d\n", n*k); // we will make periods with K size and fill with ones.
        for(int i =0 ; i< n; i++){
            for(int b: s){
                printf("%d ",b);
            }
            for(int j= 0; j < k - (int)s.size(); j++){
                printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;

}