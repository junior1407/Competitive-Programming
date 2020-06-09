// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1365/problem/B


#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 2;
int main() {
    int a[N] = {0};
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        bool sorted = true, have0=false, have1=false;
        scanf("%d",&n);
        for(int i = 0; i < n;i++ ){
            scanf("%d",&a[i]);
            if (i>0 && a[i] < a[i-1]){
                sorted = false;
            }
        }
        int temp;
        for(int i = 0; i < n; i++){
            scanf("%d",&temp);
            if (temp == 0){
                have0 = 1;
            }
            else{
                have1=1;
            }
        }
        if (sorted || (have0 && have1)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }


    }

    return 0;
}