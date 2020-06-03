// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1342/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        int has1 = 0, has0 =0;
        string s;
        cin >> s;
        int n = s.length();
        for(char i : s){
            if (i == '1'){
                has1 = 1;
            }
            if (i == '0'){
                has0 = 1;
            }
            if (has1 && has0){
                break;
            }
        }
        if (has0 && has1){
            for(int i = 0; i< n; i++){
                printf("10");
            }
        }
        else{
            for(int i = 0; i< n; i++){
                printf("%c", s[0]);
            }
        }
        printf("\n");

    }
    return 0;
}