
// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1350/problem/B


#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int maxN = 1e5 + 50;
int n, arr[maxN], length[maxN];

// length[i] -> dp where its value is the
//length of longest beautiful sequence ending in i
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &arr[i]);
      length[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = i * 2; j <= n; j += i)
      {
        if (arr[i] < arr[j])
        {
          length[j] = max(length[j], length[i] + 1);
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans = max(ans, length[i]);
    }
    printf("%d\n",ans);
  }
  return 0;
}