// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/crush
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n, m;
    scanf("%ld %ld", &n, &m);
    vector<long> arr(n + 2);
    long int a, b, k;
    for (int i = 0; i < m; i++)
    {
        scanf("%ld %ld %ld", &a, &b, &k);
        arr[a] += k;
        arr[b + 1] -= k;
    }
    long max_number = 0;
    long curr = 0;
    for (int i = 1; i <= n; i++)
    {
        curr += arr[i];
        if (curr > max_number)
        {
            max_number = curr;
        }
    }
    printf("%ld\n", max_number);
    return 0;
}
