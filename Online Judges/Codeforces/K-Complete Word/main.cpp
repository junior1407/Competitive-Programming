// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/problemset/problem/1332/C

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    string s;
    scanf("%d",&t);
    while(t--) {
        int size_string, period;
        scanf("%d %d", &size_string, &period);
        cin >> s;
        vector<vector<int>> maps(period);
        for(int i = 0; i< period; i++){
            maps[i].resize(26);
        }
        for(int i = 0 ; i< size_string; i++){
            maps[i%period][s[i] - 'a']++;
        }
        int ans = 0;
        for(int i =0 ; i< period; i++){
            int biggest = 0;
            int sum = 0;
            for(int j = 0 ; j < 26; j++ ){
                sum+= maps[i][j] + maps[period-1-i][j];
                biggest = max(biggest, maps[i][j] + maps[period-1-i][j]);
            }
            ans+=sum-biggest;
        }
        printf("%d\n", ans/2, max(0,1));

    }
    return 0;
}