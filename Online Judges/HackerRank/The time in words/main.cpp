// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/the-time-in-words/problem

#include <bits/stdc++.h>
using namespace std;


map<int, string> hashuh;

int main() {
    hashuh[1] = "one";
    hashuh[2] = "two";
    hashuh[3] = "three";
    hashuh[4] = "four";
    hashuh[5] = "five";
    hashuh[6] = "six";
    hashuh[7] = "seven";
    hashuh[8] = "eight";
    hashuh[9] = "nine";
    hashuh[10] = "ten";
    hashuh[11] = "eleven";
    hashuh[12] = "twelve";
    hashuh[13] = "thirteen";
    hashuh[14] = "fourteen";
    hashuh[15] = "quarter";
    hashuh[16] = "sixteen";
    hashuh[17] = "seventeen";
    hashuh[18] = "eighteen";
    hashuh[19] = "nineteen";
    hashuh[20] = "twenty";
    hashuh[21] = hashuh[20] + " "+ hashuh[1];
    hashuh[22] = hashuh[20] + " "+ hashuh[2];
    hashuh[23] = hashuh[20] + " "+ hashuh[3];
    hashuh[24] = hashuh[20] + " "+ hashuh[4];
    hashuh[25] = hashuh[20] + " "+ hashuh[5];
    hashuh[26] = hashuh[20] + " "+ hashuh[6];
    hashuh[27] = hashuh[20] + " "+ hashuh[7];
    hashuh[28] = hashuh[20] + " "+ hashuh[8];
    hashuh[29] = hashuh[20] + " "+ hashuh[9];
    hashuh[30] = "half";

    int h, m;
    string ans;
    scanf("%d %d", &h, &m);
    if (m == 0) {
        ans = hashuh[h] + " o' clock";
    }
    else if (m <= 30) {
        string tmp1 = ((m) == 1 ? "" : "s");
        string tmp2 = (m != 30 && m != 15 ? " minute"+ tmp1 : "");
        ans = hashuh[m] + tmp2 + " past "+ hashuh[h];
    }
    else if (m > 30) {
        string tmp1 = ((m) == 1 ? "" : "s");
        ans = hashuh[60 - m]+ (m != 45 ? " minute" + tmp1 : "")+ " to " + hashuh[h + 1];
    }
    cout << ans << endl;
    return 0;
}
