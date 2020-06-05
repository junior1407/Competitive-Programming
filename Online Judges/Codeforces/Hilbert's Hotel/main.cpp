// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1345/problem/C

#include<bits/stdc++.h>
using namespace std;
#define lli long long

int mod(int x, int m) {
    int r = x%m;
    return r<0 ? r+m : r;
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        for(int i = 0; i< n; i++){
            scanf("%d",&a[i]);
        }
        bool failed = false;
        vector<bool> used (n,false);
        for(int k = 0; k< n; k++ ){
            int pos = mod(k + a[k],n);
            if (used[pos] == true){
                failed = true;
                break;
            }
            used[pos]=true;
        }
        if (failed){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }

    }
    return 0;
}