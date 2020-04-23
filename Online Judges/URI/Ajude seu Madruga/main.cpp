// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1912

#include <bits/stdc++.h>
using namespace std;

double test(vector<int>& pieces, double cut){
    double sum = 0;
    for(int i = 0; i< pieces.size(); i++){
        if (pieces[i]> cut){
            sum+= pieces[i] - cut;
        }
    }
    return sum;
}

double binsearch(vector<int>& pieces, double start, double end, int area){
    double mid =(start+end)/2.0;
    // printf("Testing mid= %f\n", mid);
    if (end - start <=0.00001){
        return mid;
    }
    double currArea = test(pieces, mid);
    if (currArea == area){
        return mid;
    }
    if (currArea > area){
        return binsearch(pieces, mid, end, area);
    }
    return binsearch(pieces, start, mid, area);

}
int main(){
    int n, a;
    while(scanf("%d %d", &n, &a) != EOF){
        if (n== 0 && a ==0){
            break;
        }
        vector<int> pieces(n);
        int biggest= -1;
        int summ = 0;
        for(int i = 0; i< n; i++){
            scanf("%d", &pieces[i]);
            biggest = max(biggest, pieces[i]);
            summ+=pieces[i];
        }
        if (summ == a){
            printf(":D\n");
        }
        else if (summ < a){
            printf("-.-\n");
        }
        else{
            printf("%.4lf\n", binsearch(pieces, 0, biggest, a));
        }

    }


}