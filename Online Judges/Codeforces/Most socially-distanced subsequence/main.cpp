// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1364/problem/B


#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int arr[maxN] = {0};
int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> ans;
        for(int i = 0; i < n ; i++){
            scanf("%d",&arr[i]);
        }
        for(int i = 0; i< n; i++){
            if (i == 0 || i == n-1){
                ans.push_back(arr[i]);
            }
            else if ((arr[i-1] < arr[i]) !=  (arr[i]  < arr[i+1])){
                ans.push_back(arr[i]);
            }
        }

        printf("%d\n",ans.size());
        for (int i = 0; i < ans.size(); i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
       


}
