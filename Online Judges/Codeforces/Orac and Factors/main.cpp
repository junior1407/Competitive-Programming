// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://codeforces.com/contest/1350/problem/A

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		if(n%2==0)
		{
			printf("%d\n",n+2*k);
			continue;
		}
		int p = 0;
		for(int i = n; i>=2; i--)
			if(n%i==0)
		    	p = i;
		printf("%d\n",n+p+2*(k-1));
	}
	return 0;
}