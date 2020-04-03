// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1330/problem/B

#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> set1, set2;

int main(){

    int t,n;
    scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        vector<int> arr (n);
        set1.clear();
        set2.clear();
        for(int i = 0; i< n; i++){
            scanf("%d",&arr[i]);
            if (set1.count(arr[i]) <=0){
                set1[arr[i]] =1;
            }else{
                set1[arr[i]]++;
            }
        }
        // Now, all elements are in set1
        // We'll transfer one element by one to set 2 checking if its a valid permutation
        vector<pair<int,int>> ans;
        for (int i = 0 ; i< n ; i++){
            //Removing from set1
            set1[arr[i]]--;
            if (set1[arr[i]] == 0){
                set1.erase(arr[i]);
            }
            //including in set2
            if (set2.count(arr[i])<=0){
                set2[arr[i]] = 1;
            }else{
                set2[arr[i]]++;
            }
            //checking if both are valid( valid permutation and size>=1)
            if (set2.size() == i+1){
                if (set2.rbegin()->first == i+1){
                    if (set1.size() == n - i - 1){
                        if (set1.rbegin()->first == n-i-1){
                            //       printf("NICE\n");
                            ans.push_back(make_pair(i+1, n - i - 1));
                        }
                    }
                }

            }
        }
        printf("%d\n",ans.size());
        for (int i = 0; i< ans.size() ; i++){
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
}