// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/magic-square-forming

#include <bits/stdc++.h>

using namespace std;

bool isMagicSquare(vector<int> candidate);

// Complete the formingMagicSquare function below.

int formingMagicSquare(vector<vector<int>> s)
{
    vector<int> test;
    for (int i = 0; i < 3; i++)
    {
        test.insert(test.end(), s[i].begin(), s[i].end());
    }
    vector<vector<int>> allMagicSquares;
    vector<int> temp = {8, 3, 4, 1, 5, 9, 6, 7, 2};
    sort(temp.begin(), temp.end());
    do
    {
        if (isMagicSquare(temp) == true)
        {
            allMagicSquares.push_back(temp);
        }
    } while (next_permutation(temp.begin(), temp.end()));

    int minimun = INT_MAX;
    for (int i = 0; i < allMagicSquares.size(); i++)
    {
        int sum=0;
        for (int j = 0; j< 9 ; j++){
            sum += abs(test[j] - allMagicSquares[i][j]);
        }
        minimun = min (sum, minimun);
    }
    return minimun;
}

bool isMagicSquare(vector<int> candidate)
{

    int N = candidate[0] + candidate[1] + candidate[2];
    int sum1, sum2, sum3, sum4;
    //Sum of rows
    for (int i = 0; i < 3; i++)
    {
        sum1 = candidate[i * 3 + 0] + candidate[i * 3 + 1] + candidate[i * 3 + 2];
        sum2 = candidate[0 * 3 + i] + candidate[1 * 3 + i] + candidate[2 * 3 + i];
        if (sum1 != N)
        {
            return false;
        }
        if (sum2 != N)
        {
            return false;
        }
    }
    sum3 = candidate[0 * 3 + 0] + candidate[1 * 3 + 1] + candidate[2 * 3 + 2];
    sum4 = candidate[0 * 3 + 2] + candidate[1 * 3 + 1] + candidate[2 * 3 + 0];
    if (sum3 != N)
    {
        return false;
    }
    if (sum4 != N)
    {
        return false;
    }

    return true;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
