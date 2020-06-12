// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=472

*
#include <bits/stdc++.h>
using namespace std;

vector<string> s1;
vector<string> s2;

int debug(){
    printf("k ");
    return 0;
}

void solution(){
    int size1 = s1.size();
    int size2 = s2.size();
    vector<vector<int>> dp(size1+1);
    for (int i = 0; i<= size1; i++){
        dp[i].resize(size2+1);
    }
    for (int i = 0; i <= size1; i++){
        for (int j = 0; j <= size2; j++){
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                int temp1 = dp[i-1][j];
                int temp2 = dp[i][j-1];
                dp[i][j] = max(temp1, temp2);
            }

        }
    }
    std::stack<string> output;
    int i =size1;
    int j= size2;
    while(i> 0 && j> 0){
        if (s1[i-1] == s2[j-1]){
            output.push(s1[i-1]);
            i--;
            j--;
        }
        else{

            if (dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }

        }
    }

    while(!output.empty())
    {
        cout<<output.top();
        output.pop();
        if (output.empty()){
            printf("\n");
        }else{
            printf(" ");
        };
    }


}


int main(){
    int x;
    string r;
    while(cin >> r){
   //     cout << r << "]" << endl;
        if (r != "#"){;

            s1.push_back(r);
        }else{
            while(cin >> r){
             //   cout << r << "]" << endl;
                if (r!="#"){
                    s2.push_back(r);
                }else{

                    //compute and print solution
                    solution();
                    s1.clear();
                    s2.clear();
                    break;
                }
            }
        }
    }

   // printf("%d %s]\n",x,a);
    return 0;
}