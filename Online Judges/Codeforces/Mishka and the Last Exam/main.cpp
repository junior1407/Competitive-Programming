// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1093/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    vector<long long int> b(n/2);
    vector<long long int> a(n);
    long long int minn, maxx;
    for(int i = 0 ; i < n/2 ; i++){
        scanf("%lld",&b[i]);
        if (i == 0){
            a[i]= 0;
            a[n-i-1] = b[i];
            minn = 0;
            maxx = b[i];
            continue;
        }
        if (b[i] <= b[i-1]){
            while(minn + maxx!= b[i]){
                maxx--;
            }
            a[i] = minn;
            a[n-i-1]= maxx;
            // reduce max until is correct
        }else{
            //increase min until is correct
            while(minn + maxx!= b[i]){
                minn++;
            }
            a[i] = minn;
            a[n-i-1]= maxx;
        }

    }
    for(int i = 0; i < n ; i++){
        printf("%lld%c", a[i], i+1==n?'\n':' ');
    }

    return 0;
}