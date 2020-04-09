// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1157/problem/E


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
int a[MAXN], b[MAXN];
multiset <int> S;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        S.insert(b[i]);
    }
    for (int i = 0; i < n; i++) {
        int nd = (n - a[i]) % n;
        auto it = S.lower_bound(nd);
        if (it == S.end()){
            it = S.begin();
        }
        printf("%d%c", (a[i] + *it) % n, i + 1 < n? ' ': '\n');
        S.erase(it);
    }
    return 0;
}