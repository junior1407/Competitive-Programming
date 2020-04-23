// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1025

#include <bits/stdc++.h>
using namespace std;
int ascending(void const *a, void const *b )
{
    return (*(int*)a - *(int*)b );
}
void binsearch(int marbles[], int start, int end, int elem){
    int midIndex = (start+end)/2;
    int midValue = marbles[midIndex];

    if (midValue == elem){
        while((midIndex> 0) && (marbles[midIndex-1] ==elem )){
            midIndex--;
        }
        printf("%d found at %d\n", elem, midIndex+1);
    }
    else if(midIndex == end || (midIndex<0 || end < 0)){
        printf("%d not found\n", elem);

    }
    else if( midValue > elem){ //Lets go left
        binsearch(marbles, start, midIndex-1, elem);
    }
    else if (midValue < elem){
        binsearch(marbles, midIndex+1, end, elem);
    }
}

int main(){
    int n, q;
    int counter = 1;
    while(scanf("%d %d", &n, &q) != EOF){
        if (n==0 && q == 0){
            break;
        }
        printf("CASE# %d:\n", counter);
        counter++;
        int marbles[n];
        for(int i = 0; i< n; i++){
            scanf("%d", &marbles[i]);
        }

        qsort(marbles, n, sizeof(int), ascending);
        int temp;
        for(int i = 0; i < q; i++){
            scanf("%d",&temp);
            binsearch(marbles, 0, n-1, temp);
        }
    }


}