// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1359/problem/D

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main() {
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i = 0; i< n; i++){
        scanf("%d",&arr[i]);
    }
    long long ans = 0;
    for(int removing = 0; removing <=30; removing++){
        long long curr = 0;
        long long skip = 0;
        for(int i =0; i< n; i++){
            // This case is invalid.
            if (arr[i]>removing){
                curr+=-INF;
            }
            else{
                curr +=arr[i];
            }
            skip = min(skip, curr);
            ans = max(ans, (curr - skip) - removing);
        }
    }
    printf("%lld",ans);
    return 0;
}