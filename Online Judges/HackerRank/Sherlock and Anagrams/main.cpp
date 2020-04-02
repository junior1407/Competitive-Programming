// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/sherlock-and-anagrams

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.

void generateAnagrams(string s, map<string, int> &dict)
{
    int length = s.length();
    string s1, s2;
    for (int i = 0; i < length; i++)
    {
        for (int j = 1; j < length - i + 1; j++)
        {
            s1 = s.substr(i, j);
            sort(s1.begin(), s1.end());
            dict[s1]++;
            //cout << s1 << endl;
        }
    }
}

int sherlockAndAnagrams(string s)
{
    //h + dp(ello) [0,0]  + [1,4] 4
    //he + dp(llo) [0,1]  + [2,4] 3
    //hel + dp(lo) [0,2]  + [3,4] 2
    //hell  + dp(o) [0,3]  + [4,4]
    //hello   [0,4]  + [,]
    map<string, int> dict;
    generateAnagrams(s, dict);
    long long ans = 0;
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        ans += (long long)(it->second) * (it->second - 1) / 2;
    }

    return ans;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);
        int result = sherlockAndAnagrams(s);
        cout << result << "\n";
    }
    //  fout.close();
    return 0;
}
