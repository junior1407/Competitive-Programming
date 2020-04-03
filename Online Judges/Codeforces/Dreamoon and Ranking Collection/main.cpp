// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1330/problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, more_contests;
    scanf("%d", &t);
    for(int z = 0; z < t; z++)
    {
        scanf("%d %d", &n, &more_contests);
        vector<int> temp_input(n);
        int maxx = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp_input[i]);
            maxx = max(maxx, temp_input[i]);
        }
        vector<int> counter(maxx + 2 + more_contests, maxx+more_contests+2);
        vector<int> flag(maxx + 2 + more_contests,0);
        for (int i = 0; i < n; i++)
        {
            flag[temp_input[i]]++;
        }
        counter[0] = 0;
        int i;
        int remainingContests = more_contests;
        int ans;
        for (i = 1; i < maxx + more_contests + 2; i++)
        {
            //printf("i = %d,  flag[i] = %d,  more = %d\n",i, flag[i], remainingContests);
            if (flag[i] >= 1)
            {
                counter[i] = counter[i - 1];
            }
            else
            {
                if (remainingContests <= 0)
                {
                    ans = i-1;
                    break;
                }
                counter[i] = counter[i - 1] + 1;
                remainingContests--;
            }
        }
        printf("%d\n", ans);
    }
}