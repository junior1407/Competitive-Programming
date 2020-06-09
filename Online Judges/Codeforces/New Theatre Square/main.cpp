// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1359/problem/B

#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int calculate(int counter){
    // x -> price 1x1
    // j -> price 1x2
    return (counter/2)*y + (counter%2)*x;


}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d %d",&n,&m,&x,&y);
        y = min(y, 2*x);
        int ans = 0;
        for(int i = 0; i<n; i++){
            string s;
            cin >> s;
            int counter = 0;
            for(int j = 0; j<= m; j++){
                if (j == m){
                    if (counter > 0){
                        ans += calculate(counter);
                    }
                }
                if (s[j] == '.'){
                    counter ++;
                }
                if (s[j] == '*'){
                    ans += calculate(counter);
                    counter = 0;
                }
            }

        }
        printf("%d\n",ans);
    }

    return 0;
}