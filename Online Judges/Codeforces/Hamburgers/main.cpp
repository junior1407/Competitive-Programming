// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1244/problem/E


#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int maxN = 1e5 + 5;
int n;
lli k;
lli arr[maxN];

lli test(lli minimum, lli maximum)
{
    lli cost = 0;
    // Increasing prefix until reaches minimum
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= minimum)
        {
            break;
        }
        cost += minimum - arr[i];
    }
    //decreasing suffix until reaches maximum
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] <= maximum)
        {
            break;
        }
        cost += arr[i] - maximum;
    }
    return cost;
}
bool isPossible(lli difference)
{
    lli start = 1, end = 1e9;
    while (start < end - 2)
    {
        lli mid_1 = (2 * start + end) / 3;
        lli mid_2 = (start + 2 * end) / 3;
        lli cost_1  = test(mid_1, mid_1 + difference);
        lli cost_2 = test(mid_2, mid_2 + difference);
        if (cost_1 <= cost_2)
            end = mid_2;
        else
            start = mid_1;
    }
    lli ans = 1e18;
    for (int i = start; i <= end; i++)
        ans = min(ans, test(i, i + difference));
    return ans <= k;
}
int main()
{

    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    lli start = 0;
    lli end = 1e9;
    while (start < end)
    {
        lli mid = (start + end) / 2;
        if (isPossible(mid))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    printf("%lld\n", start);

    return 0;
}
