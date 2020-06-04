// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1342/problem/C


#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxx=4e4+100;
int dp[maxx];
int a,b,q;
int n;

ll fcs(ll cnt)
{
    return (ll)dp[n-1]*(ll)(cnt/n)+(ll)dp[cnt%n];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&q);
        dp[0]=0;
        n=a*b;
        for(int i=1;i<=n;i++)
        {
            if(i%a%b==i%b%a) dp[i]=dp[i-1];
            else dp[i]=dp[i-1]+1;
        }
        ll l,r;
        while(q--)
        {
            scanf("%lld %lld",&l,&r);
            printf("%lld\n",fcs(r)-fcs(l-1));
        }
    }
    return 0;
}