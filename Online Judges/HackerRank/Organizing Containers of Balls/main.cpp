// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem


#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> capacity(n);
        vector<int> types_of_each(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                scanf("%d",&x);
                capacity[i]+=x;
                types_of_each[j]+=x;
            }
        }
        int impossible = 0;
        for(int i = 0; i< n; i++){
            int j = 0;
            for(j = i; j < n; j++ ){
                if (capacity[i] == types_of_each[j]){
                    int temp = types_of_each[j];
                    types_of_each[j] = types_of_each[i];
                    types_of_each[i] = temp;
                    break;
                }
            }
            if (j == n){
                impossible=1;
                break;
            }
        }
        printf("%s\n", impossible == 0? "Possible": "Impossible");

    }
    return 0;
}
