#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
//longest common subsequence and scs
// https://leetcode.com/problems/shortest-common-supersequence/submissions/

int dp[MAX_N][MAX_N];
    
int lcs(string& s1, string s2, int i1, int i2) {
    if (i1 >= s1.size() || i2 >= s2.size()) {
        return 0;
    }
    if (dp[i1][i2] != -1) {
        return dp[i1][i2];
    }
    if (s1[i1] == s2[i2]) {
        int ans = 1 + lcs(s1,s2, i1+1, i2+1);
        dp[i1][i2] = ans;
        return ans;
    }
    int ans = max(lcs(s1,s2, i1+1, i2), lcs(s1,s2, i1, i2+1));
    dp[i1][i2] = ans;
    return ans;
}

string build_lcs(string &s1, string &s2) {
    int n_lcs = lcs(s1, s2, 0, 0);
    int i1 = 0, i2 = 0;
    string s = "";
    while (i1 < s1.size() && i2 < s2.size()) {
        if (s1[i1] == s2[i2]) {
            s += s1[i1];
            i1++; i2++;
        }
        else if (dp[i1+1][i2] > dp[i1][i2+1]) {
            s+= s1[i1]; i1++;
        }
        else {
            s+= s2[i2]; i2++;
        }
    }
    while( i1 < s1.size()) {
        s+= s1[i1++];        
    }
    while( i2 < s2.size()) {
        s+= s2[i2++];        
    }
    cout << s;
    return s;
}

string shortestCommonSupersequence(string str1, string str2) {
    memset(dp,  -1, MAX_N* MAX_N * sizeof(int));
    return build_lcs(str1, str2);
}

}