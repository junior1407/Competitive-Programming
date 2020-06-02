// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/problemset/problem/1132/B


#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for (int i = 0; i< n; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr.begin(), arr.end());
    for(int i = n-1; i >=0; i--){
        if (arr[i] <= i+1){
            printf("%d\n",i+2);
            return;
        }
    }
    printf("1\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}