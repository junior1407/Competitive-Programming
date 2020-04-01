// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/pairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, x;
    scanf("%d %d", &N, &K);
    map<int, bool> hashmap_uh;
    for (int i = 0 ; i < N; i++){
        scanf("%d",&x);
        hashmap_uh[x] = true;
    }
    int result = 0;
    for (map<int, bool>:: iterator it = hashmap_uh.begin(); it != hashmap_uh.end(); it++){
        int value = it->first;
        if (hashmap_uh.find(value-K) != hashmap_uh.end()){
            result ++;
        }
    }
    cout<<result<<endl;

    return 0;
}
