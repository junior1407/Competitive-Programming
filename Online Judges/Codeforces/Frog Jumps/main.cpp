// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1324/problem/C

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    string s;
    scanf("%d",&t);
    while(t--){
        cin >> s;
        int maxx = -1;
        s = "R"+s+"R";
        int lastRIndex = 0;
        int maxDistance = -1;
        for (int i = 1; i< s.length(); i++){
            if (s[i] == 'R'){
                maxDistance = max(maxDistance,  i - lastRIndex);
                lastRIndex = i;
            }
        }
        printf("%d\n", maxDistance);
        //   cout<< s<<endl;
    }
    return 0;
}