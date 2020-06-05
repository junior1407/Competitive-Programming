// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1348/problem/C

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d %d",&n, &k);
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        // if the first k characters aren`t equal, the last one will be the last ;)
        if (s[0]!=s[k-1]){
            printf("%c\n",s[k-1]);
            continue;
        }
        printf("%c",s[0]);
        //if remaining letters aren't the same, we append remaining letters to answer
        if (s[k]!=s[n-1]){
            for (int i=k;i<n;i++)
                printf("%c",s[i]);
        }
        else{
            //remaining letters are the same, so we distribute evenly
            for (int i=0;i<(n-k+k-1)/k;i++)
                printf("%c",s[n-1]);
        }
        printf("\n");
    }
    return 0;

}