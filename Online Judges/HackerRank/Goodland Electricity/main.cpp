// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/pylons/problem



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    vector<int> cities(n);
    for(int i = 0; i < n; i++){
        scanf("%d",&cities[i]);
    }
    int ans = 0,  last = -1, front = -1;
    while(front < n-1) {
        int seek = min(front+k, n-1);
        while(seek > last && cities[seek] == 0)
            seek -= 1;

        if(seek == last) {
            ans = -1;
            break;
        }
    
        ans += 1;
        last = seek;
        front = seek + k - 1;
    }
    printf("%d\n",ans);
    return 0;
}