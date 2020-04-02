// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/max-array-sum/problem


#include <bits/stdc++.h>

using namespace std;

int dp(int a, int b, map<pair<int,int>, int>& DP, vector<int>& arr){
    if (a >= arr.size()){
        return 0;
    }
    map<pair<int,int>, int>::iterator iter = DP.find(make_pair(a,b));
    if (iter != DP.end()){
        return iter->second;
    }else{
        // case 1: take a
        int case1 = arr[a] + dp(a+2,b, DP, arr);

        //case 2 : dont take a
        int case2 = dp(a+1, b, DP, arr);
        DP[make_pair(a,b)] =  max(case1, case2);
        return DP[make_pair(a,b)];
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    map<pair<int, int>, int> DP;
/*
    for (map<tuple<int,int>, int>::iterator it = DP.begin(); it != DP.end(); ++it)
    {
        printf("%d,%d %d", it->first[0],it->first[1], it->second);
    }*/
    for (int i =0 ; i< n; i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n", dp(0,n-1,DP, arr));

    return 0;
}
