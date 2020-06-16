// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/problemset/problem/371/C


#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli recipe[3] = {0};
lli stock[3]= {0};
lli price[3] = {0};
lli budget;

bool test(lli num){
    lli buy_b =  max(0LL,num * recipe[0] - stock[0]); 
    lli buy_s =  max(0LL,num * recipe[1] - stock[1]); 
    lli buy_c =  max(0LL,num * recipe[2] - stock[2]); 
    lli total = buy_b*price[0] + buy_s*price[1] + buy_c*price[2];
    return( total <= budget);
}

lli bin_search(){
    lli start = 0;
    lli end = 1e14;
    lli mid;
    while(end > start){
///printf("%lld %lld\n", start, end);
        mid = (start + end)/2 + (start + end)%2;
       // printf("%lld %lld %lld\n", start, mid, end);
        if (test(mid)){
            start = mid;
        }
        else{
            end = mid-1;
        }
    }
    return start;
}

int main(){
    string recipe_s;
    cin >> recipe_s;

    // B -> 0,   S -> 1, C-> 2
    for(int i = 0; i< recipe_s.length(); i++){
        if (recipe_s[i] == 'B'){
            recipe[0]++;
        }
        else if (recipe_s[i]=='S'){
            recipe[1]++;
        }
        else if (recipe_s[i] == 'C'){
            recipe[2]++;
        }
    }
    scanf("%lld %lld %lld",&stock[0], &stock[1], &stock[2]);
    scanf("%lld %lld %lld",&price[0], &price[1], &price[2]);
    scanf("%lld",&budget);
    printf("%lld\n", bin_search());
    return 0;
}
