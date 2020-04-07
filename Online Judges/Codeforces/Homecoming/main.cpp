// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1315/problem/B


#include <bits/stdc++.h>
using namespace std;


int main() {
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases--){
        int a, b, money;
        scanf("%d %d %d",&a,&b,&money);
        string s;
        cin>>s;
        int n = s.size();
        vector<long long int> dp(n);
        int last_a = n - 1, last_b = n - 1;
        for(int i=n-2; i>=0; i--)
        {
            if(s[i] == 'A')
            {
                dp[i] = a + dp[last_b];
                last_a = i;
            } else
            {
                dp[i] = b + dp[last_a];
                last_b = i;
            }
        }

        for(int i=0; i<n; i++)
            if(dp[i] <= money)
            {
                printf("%d\n", i + 1);
                break;
            }
    }

    return 0;
}