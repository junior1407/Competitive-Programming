// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1348/problem/E

#include<bits/stdc++.h>
using namespace std;


int n, k;
int a[505], b[505];
bool dp [505][505]; // extra red berries.

int main(){
    scanf("%d %d",&n, &k);
    long long sumA=0, sumB=0;
    for(int i =1; i<= n;i++){
        scanf("%d %d",&a[i], &b[i]);
        sumA+=a[i];
        sumB+=b[i];
    }
    dp[0][0] = true;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j < k; j++){
            // We`re leaving a[i]%k extra berries
            dp[i][j]=dp[i-1][(j-a[i]%k+k)%k]; // checking how many we need to leave "j" reds and fill buckets.
            for (int l=0;l<=min(k-1,a[i]);l++){
                //check if we can leave l extra red berries
                if ((a[i]-l)%k+b[i]>=k) { // if leaving l extra berries we can still form basckets with blue
                    dp[i][j] |= dp[i - 1][(j - l + k) % k];
                }
            }
        }
    }

    long long ans=0;
    for (int i=0;i<k;i++){
        if (dp[n][i])
            ans=max(ans,(sumA+sumB-i)/k);
    }
    cout<<ans<<endl;
}
