// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1333/problem/C

#include<bits/stdc++.h>
using namespace std;
map<long long int,int> mp;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a (n+1);
    vector<long long int> s (n+1);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i];
    }
    int l=0;
    mp[0]=0;

    // It has a bad sum if for a set ai ... to aj, suffixsum[i-1] = suffixsum[j]
    // so we have to find rightmost border.

    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        // here we find the right limit
        if(mp.find(s[i])!=mp.end()){
            //   printf("Found %lld\n", s[i]);
            l=max(l,mp[s[i]]+1);
        }
        ans+=i-l;
        mp[s[i]]=i;
        // printf("i = %d finished with ans = %lld,  l = %d\n", i, ans, l );
    }
    printf("%lld\n", ans);
    return 0;
}