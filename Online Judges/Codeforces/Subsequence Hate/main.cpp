// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1363/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[1001];
        getchar();
        scanf("%s",s);
        int n = strlen(s);
        int ones = 0, zeros = 0;
        for(int i = 0 ; i< n ; i++){
            ones += s[i] == '1';
            zeros += s[i] == '0';
        }

        int ans = min(ones, zeros);  // worst case.
        int counted_0 = 0, counted_1 = 0;
        for(int i = 0 ; i< n ; i++){
            counted_0 += s[i] =='0';
            counted_1 += s[i] =='1';
            // 0000011111  Transform all counted_1 to 0.  The rest will be turned to 1s
            ans = min(ans, counted_1 + (zeros - counted_0));
            // 111110000000  opposite
            ans = min (ans, counted_0 + (ones - counted_1));
        }
        printf("%d\n", ans);
    }
}
