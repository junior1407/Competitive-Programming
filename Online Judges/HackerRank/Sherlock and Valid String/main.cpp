// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freq(26);
    int minn = INT_MAX, maxx = INT_MIN;
    for (int i = 0; i< s.length() ; i++){
        freq[s[i] - 'a']++;
    }
    sort(freq.begin(), freq.end());
    int start_index = 0;
    while(freq[start_index] == 0){
        start_index++;
    }
    maxx = freq[25];
    minn = freq[start_index];
    if (minn == maxx){
        printf("YES\n");
        return 0;
    }
    if (maxx - minn == 1){
        if (freq[25] > freq[24]) {
            printf("YES\n");
            return 0;
        }
    }
    if (freq[start_index] == 1 && freq[start_index+1] == maxx){
        printf("YES\n");
        return 0;
    }


    printf("NO\n");
    return 0;
}
