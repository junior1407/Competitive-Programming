// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/connected-cell-in-a-grid

#include <bits/stdc++.h>
using namespace std;


vector <vector<int>> arr;
int n,m;

bool isValid(int x, int y){
    return (x<n && y <m) && (x>=0 && y>=0);
}
int findBiggest(int x, int y){
    arr[x][y] = 0;
    int size = 1;
    for (int i = -1 ; i <=1; i++){
        for (int j = -1; j <=1 ; j++){
            if (i == 0 and j == 0){
                continue;
            }
            if (isValid(x+i,y+j) && arr[x+i][y+j] == 1){
                size+= findBiggest(x+i, y+j);
            }
        }
    }
    return size;
}

int solution(){
    int maximo = -1, curr;
    for (int i = 0; i< n; i++){
        for (int j = 0 ; j< m ; j++){
            if (arr[i][j]==1){
                curr = findBiggest(i,j);
                maximo = max(curr, maximo);
            }
        }
    }
    return maximo;

}


int main() {
    scanf("%d %d", &n, &m);
    arr.resize(n);
    for (int i = 0; i< n ; i++){
        arr[i].resize(m);
    }
    for (int i = 0 ; i< n; i++){
        for (int j= 0; j < m ;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    // printf("Oi");
    printf("%d\n", solution());

    return 0;
}
