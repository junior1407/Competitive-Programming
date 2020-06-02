// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1358/problem/D

#include <bits/stdc++.h>
using namespace std;
#define lli long long
int main(){
    lli n,x;
    scanf("%lld %lld",&n, &x);
    vector<lli> A(2*n);
    for(int i = 0; i< n ; i++){
        scanf("%lld",&A[i]);
        A[i+n] = A[i];
    }
    n = n*2;
    vector<lli> B = {0}, C={0};
    for(int i = 0; i<n; i++){
        B.push_back(B.back() + A[i]);  // cumm sum of days after ith month.
        C.push_back(C.back() + (A[i] * (A[i] + 1)) / 2); //cumm sum of hugs after ith month
    }
    lli ans = 0;
    for(int i = 0; i< n; i++){
        if (B[i+1] >= x){ // i is left,  temp is right.
            lli temp = upper_bound(B.begin(), B.end(), B[i+1] - x) - B.begin();
            lli hugs_count = C[i+1] - C[temp];
            lli days_count = B[i+1] - B[temp];
            lli missing_day =  x - days_count;
            // temp is start  inclusive.  i+1 is end inclusive
            hugs_count += ((A[temp - 1] * (A[temp - 1] + 1)) / 2); // if necessary all days in the previous month
            hugs_count -= (((A[temp - 1] - missing_day) * (A[temp - 1] - missing_day + 1)) / 2); // remove the not necessary ones.
            ans = max(ans, hugs_count);
        }
    }
    printf("%lld\n",ans);


}