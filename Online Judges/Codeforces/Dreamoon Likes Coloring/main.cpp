// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1330/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int number_cells, number_colors;
    scanf("%d %d", &number_cells, &number_colors);
    vector<int> l(number_colors+1);
    vector<long long int> sufixo(number_colors+2);
    for (int i = 1; i<= number_colors; i++){
        scanf("%d",&l[i]);
        if (l[i] + i - 1>number_cells){ // If any color attempts to color past the number of cells.
            printf("-1\n");
            return 0;
        }
    }
    for(int i = number_colors; i>0; i--){
        sufixo[i] = sufixo[i+1] + l[i];
    }
    if (sufixo[1] < number_cells){
        printf("-1\n"); // If there is not enough colors to fill the cells.
        return 0;
    }
    long long ans=-1;
    for (int i = 1; i<=number_colors; i++){
        // The ith color must painted starting from i or from the 1 cell to the left where the future colors can be used to color.
        ans = max((long long) i, number_cells - sufixo[i] + 1);
        printf("%lld",ans);
        if (i+1 == number_colors){
            printf("\n");
        }
        else{
            printf(" ");

        }
    }
    return 0;

}
