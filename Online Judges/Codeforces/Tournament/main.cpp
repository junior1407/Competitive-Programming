// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1260/problem/E
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long int> prices;
vector<int> many_defeated_by_round;
int n_rounds;
map<pair<int,int>, long long int> hashmapuh;

long long int solution(int bribed_quantity, int nextFighter){
    //Bribed_index = It represents that this is the ith bribe or the ith round. It also represents that were're trying to bribe
    // this person on the leafs.
    long long int total= LONG_LONG_MAX;

    if (prices[nextFighter] == -1){
        return 0;  // Do not bribe your own friend!
    }
    auto temp = hashmapuh.find(make_pair(bribed_quantity,nextFighter));
    if (temp != hashmapuh.end()){
        return temp->second;
    }
    if (bribed_quantity < n_rounds){ //It`s possible to bribe one by turn. Let`s check if its possible to bribe this one.
        //By bribing this one, the fight is won so we have to move to the next one.
        total = min(total, solution(bribed_quantity+1, nextFighter+1) + prices[nextFighter]);
    }
    if (many_defeated_by_round[bribed_quantity] > nextFighter){
        // If we`ve surpassed the limit of bribes, we won`t bribe the next fighter
        // Our bribed champion will take him on.
        total = min(total, solution(bribed_quantity, nextFighter+1));
    }
    hashmapuh[make_pair(bribed_quantity,nextFighter)] = total;
    return total;

}

int main() {
    scanf("%d",&n);
    n_rounds = log2(n);
    prices.resize(n+1);
    for (int i  = 0;  i<n; i++){
        scanf("%lld", &prices[n-i-1]);
    }
    many_defeated_by_round.resize(n_rounds+1);
    many_defeated_by_round[1] = n/2;
    int remaining = n/2;
    for(int i = 2; i <= n_rounds; i++){
        many_defeated_by_round[i] = many_defeated_by_round[i-1] + remaining/2;
        remaining = remaining - remaining/2;
    }


    printf("%lld\n",solution(0,0));




    return 0;
}