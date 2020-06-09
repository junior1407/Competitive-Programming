// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1365/problem/C




#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int main() {
    int n;
    scanf("%d",&n);
    vector<int> matches(n+2), positions(n+2), a(n+2), b(n+2);
    for(int i = 1; i<=n; i++){
        scanf("%d",&a[i]);
        positions[a[i]] = i;
    }
    for(int i = 1; i<=n; i++){
        scanf("%d",&b[i]);
        int offset = positions[b[i]] - i;
        if (offset < 0){
            offset +=n;
        }
        matches[offset]++;
    }
    int ans = 0;
    for(int i = 0 ; i<=n; i++){
        ans = max (ans, matches[i]);
    }

    printf("%d\n",ans);

    return 0;
}