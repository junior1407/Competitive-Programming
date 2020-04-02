// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/encryption/problem


#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string str) {


    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    int size = str.length();
    int rows = floor(sqrt(size));
    int columns = ceil(sqrt(size));
    int area = rows * columns;
    while (area < size)
    {
        if (rows < columns)
        {
            rows++;
        }
        else
        {
            columns++;
        }
        area = rows * columns;
    }
    int index = 0;
    char matrix[rows][columns] = {0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (index < size)
            {
                matrix[i][j] = str[index++];
            }
        }
    }
    string encrypted = "";
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][j] != 0)
            {
                encrypted += matrix[i][j];
            }
        }
        if (j +1 != columns){
            encrypted += " ";
        }
    }
    return encrypted;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
