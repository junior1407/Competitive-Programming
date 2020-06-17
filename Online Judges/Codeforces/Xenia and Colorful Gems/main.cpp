// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1337/problem/D


#include <bits/stdc++.h>
using namespace std;

int t, nr, ng, nb;
long long ans;

long long square(int x)
{
    return 1ll * x * x;
}

void solve(vector<int> a, vector<int> b, vector<int> c)
{
    for (auto x : a)
    {
        auto y = lower_bound(b.begin(), b.end(), x);
        auto z = upper_bound(c.begin(), c.end(), x);
        if (y == b.end() || z == c.begin())
        {
            continue;
        }
        z--;
        ans = min(ans, square(x - *y) + square(*y - *z) + square(*z - x));
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &nr, &ng, &nb);
        vector<int> r(nr), g(ng), b(nb);
        for (int i = 0; i < nr; i++)
        {
            scanf("%d", &r[i]);
        }
        for (int i = 0; i < ng; i++)
        {
            scanf("%d", &g[i]);
        }
        for (int i = 0; i < nb; i++)
        {
            scanf("%d", &b[i]);
        }
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        ans = 9e18;
        solve(r, g, b);
        solve(r, b, g);
        solve(g, b, r);
        solve(g, r, b);
        solve(b, r, g);
        solve(b, g, r);
        cout << ans << endl;
    }
    return 0;
}
