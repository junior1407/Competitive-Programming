// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1138/problem/A


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int a,b;
    scanf("%d",&n);
    vector<int> sushi(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",& sushi[i]);
    }
    vector<int> solution;
    int count = 1;


    //we're creating a list with the lengths of each segment
    for (int i = 1; i< n; i++){
        if (sushi[i] == sushi[i-1]){
            count++;
        }else{
            solution.push_back(count);
            count = 1;
        }
    }
    int best = 0 ;
    solution.push_back(count); // The last one wasnt included in the loop because it would need to
    // check the n index that does not exist
    for(int i =0; i<solution.size() - 1; i++){
        // the answer is the best minimum between two adjancets segments.
        if (min(solution[i], solution[i+1]) > best){
            best = min(solution[i], solution[i+1]);
        }
    }
    printf("%d\n", best*2);
    return 0;
}