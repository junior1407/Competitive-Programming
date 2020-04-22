// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3183


#include <bits/stdc++.h>
using namespace std;

bool test(vector<int>& heights, int k){
    for(int i = 0; i< heights.size()-1; i++){
        if (heights[i+1] - heights[i] > k){
            return false;
        }
        if (heights[i+1] - heights[i] == k){
            k --;
        }
    }
    return true;
}

int binsearch(vector<int>& heights, int start, int end){
    int middle = (start+end)/2;
    //2
    //5
    //1 6 7 11 13
    //4
    //3 9 10 14
    // printf("start=%d, end= %d, test= %d\n", start, end,  test(heights, middle)?1:0);
    if (start == end){
        return start;
    }
    if (test(heights, middle)){
        return binsearch(heights, start, middle);
    }
    return binsearch(heights, middle+1, end);


}

int main(){
    int t, n;
    scanf("%d",&t);
    for(int z = 1; z<= t; z++){
        scanf("%d",&n);
        vector<int> heights(n+1);
        int maxi = 0;
        for(int i = 1; i<= n; i++){
            scanf("%d", &heights[i]);
            maxi+=heights[i];
        }
        printf("Case %d: %d\n", z, binsearch(heights, 1, maxi));
    }


}