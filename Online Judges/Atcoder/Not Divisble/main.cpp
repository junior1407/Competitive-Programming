// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://atcoder.jp/contests/abc170/tasks/abc170_d


#include <bits/stdc++.h>
using namespace std;

int ap[1000000+20] = {0},n,a[200000+20];
int main(){
    scanf("%d",&n);
    for(int i = 1; i <=n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i = 1; i <=n; i++) {
        if(a[i]==a[i-1]){
            ap[a[i]]=1;
        }
    }
    int res=0;
    for(int i = 1; i <=n; i++) {
        if(!ap[a[i]])
            res++;
        if(a[i]!=a[i-1]){
            for(int j=2*a[i];j<=1000000;j+=a[i]){
                ap[j]=1;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}