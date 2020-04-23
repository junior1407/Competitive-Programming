// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=288

#include <bits/stdc++.h>
using namespace std;

void fill(vector<string>& matrix, int x, int y, int size){
    if ((x < 0 || x>=size ) || ( y< 0 || y>=size)){
        return;
    }
    if (matrix[x][y] == '0'){
        return;
    }
    matrix[x][y]= '0';
    fill(matrix,x-1,y-1,size);
    fill(matrix,x-1, y,size);
    fill(matrix,x-1, y+1,size);
    fill(matrix,x, y-1,size);
    fill(matrix,x, y+1,size);
    fill(matrix,x+1, y-1,size);
    fill(matrix,x+1, y,size);
    fill(matrix,x+1, y+1,size);
}
void search(vector<string>& matrix, int test){
    int counter = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j =0; j < matrix[i].length(); j++){
            if (matrix[i][j] == '1'){
                counter++;
                fill(matrix,i,j, matrix.size());
            }
        }
    }
    printf("Image number %d contains %d war eagles.\n", test, counter);

}
int main(){
    int n;
    int counter = 1;
    while(scanf("%d", &n) != EOF){
        vector<string> matrix(n);
        for(int i =0 ; i< n ; i++){
            cin >> matrix[i];
        }
        search(matrix, counter);
        counter++;
    }


}