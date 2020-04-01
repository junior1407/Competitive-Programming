// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/hackerland-radio-transmitters


#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, radius;
    scanf("%d %d",&N, &radius);
    vector<int> arr (N);
    for (int i=0; i< N; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr.begin(), arr.end());
    int counter= 0; int where_put;
    for (int i = 0; i<N;){
        where_put = arr[i] + radius;// ideal
        i++;
        while(i < N && arr[i] <= where_put){
            i++;
        }
        i--;
        where_put = arr[i];
        counter++;
        while(i< N && arr[i] <= where_put + radius){
            i++;
        }
    }
    printf("%d\n",counter);
    return 0;
}

