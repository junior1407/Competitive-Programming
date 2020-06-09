// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1365/problem/A

#include<bits/stdc++.h>
using namespace std;
const int N = 50 + 2;
int main() {
    int a[N][N] = {0};
    int t;
    scanf("%d",&t);
    while (t--) {
        set<int> r,c;
        int n, m;
        scanf("%d %d",&n,&m);
        for(int i = 1; i<= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d",&a[i][j]);
                if (a[i][j] == 1){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        int remainingMoves = min(n-r.size(), m -c.size());
        if (remainingMoves%2 !=0){
            cout << "Ashish" << endl;
        }else{
            cout << "Vivek" << endl;
        }

    }
    return 0;
}