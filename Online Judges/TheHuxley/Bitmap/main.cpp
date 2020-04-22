// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.thehuxley.com/problem/821

#include <bits/stdc++.h>
using namespace std;

string solve(vector<vector<int>>& matrix, int x_start, int x_end, int y_start, int y_end){
    if (x_start>x_end ||  y_start > y_end){
        return "";
    }
    if ((x_start == x_end) && (y_start==y_end)){
        if (matrix[x_start][y_end]==1){
            return "1";
        }
        return "0";
    }
    int x_middle = (x_start + x_end)/2;
    int y_middle = (y_start + y_end)/2;
    string a = solve(matrix, x_start, x_middle, y_start, y_middle);
    string b = solve(matrix, x_start, x_middle, y_middle + 1, y_end);
    string c = solve(matrix, x_middle + 1, x_end, y_start, y_middle);
    string d = solve(matrix, x_middle + 1, x_end, y_middle + 1, y_end);
    string all = a+b+c+d;
    char pivot;
    pivot = all[0];
    bool flag = true;
    for(int i = 0; i< all.length(); i++){
        if (all[i] != pivot){
            flag = false;
        }
    }
    if (flag){
        return a;
    }
    else{
        string ans;
        ans = "D" +all;
        return ans;
    }
}
int main(){
    int t, n, m;
    scanf("%d",&t);
    for(int z = 1; z<= t; z++){
        scanf("%d %d",&n, &m);
        getchar();
        vector<vector<int>> matrix(n);
        char c;
        for(int i = 0 ; i< n; i++){
            matrix[i].resize(m);
            for(int j = 0; j< m; j++){
                c = getchar();
                if (c=='1'){
                    matrix[i][j] = 1;
                }

            }
            getchar();
        }
        for(int i =0 ; i< n; i++){
            for(int j= 0; j< m;j++){

            }
        }
        string ans = solve(matrix, 0,n-1, 0, m-1);
        for(int i = 0; i< ans.length(); i++){
            printf("%c", ans[i]);
            if ((i+1) % 50 == 0){
                printf("\n");
            }
        }
        if ((ans.length()) % 50 !=0 ){
            printf("\n");
        }
    }
}
