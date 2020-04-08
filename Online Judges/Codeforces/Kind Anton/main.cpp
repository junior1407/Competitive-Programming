// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1333/problem/B


#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d",&b[i]);
        }
        int plus1 = 0, minus1= 0;
        int yes = 1;
        for(int i = 0; i< n; i++){

            if (a[i] > b[i] && minus1 == 0){

                printf ( "NO\n" );
                yes = 0;
                break;
            }
            if (a[i] < b[i] && plus1 == 0){
                printf ( "NO\n" );
                yes = 0;
                break;
            }
            if (a[i]==1){
                plus1 = 1;
            }
            if (a[i]==-1){
                minus1= 1;
            }
        }
        if (yes){
            printf ( "YES\n" ) ;
        }


    }
    return 0;
}
