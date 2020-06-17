// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1337/problem/B


#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n, m, hp;
	scanf("%d",&t);
	while(t--){
        scanf("%d %d %d",&hp, &n, &m);
        int new_hp;
       // printf("HP was %d %d %d\n", hp,n,m);
        for(int i = 0; i< n; i++){
            new_hp = hp/2;
            new_hp+=10;
            if (new_hp >= hp){
                break;
            }
            hp = new_hp;
        }
      //  printf("HP x %d\n", hp);
        hp -= 10 * m;
      //  printf("HP y %d\n", hp);
        if (hp <= 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

	}
}
