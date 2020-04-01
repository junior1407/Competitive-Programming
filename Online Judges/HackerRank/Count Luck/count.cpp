// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/count-luck

#include <bits/stdc++.h>

using namespace std;

enum Direction : int
{
    dir_right = 0,
    dir_left = 1,
    dir_up = 2,
    dir_down = 3,
    none
};
bool isValid(char **matrix, int x, int y, int rows, int columns)
{
    if (x < 0 || x >= rows || y < 0 || y >= columns)
    {
        return false;
    }
    if (matrix[x][y] == 'X')
    {
        return false;
    }
    return true;
}

int backtrack(char **matrix, int x, int y, int rows, int columns, enum Direction dir, int n_changes, bool &finished)
{
    if (finished == true){
        return -1;
    }
    if (matrix[x][y] == '*'){
        finished = true;
        return n_changes;
    }
    matrix[x][y] = 'X';
    int arr[5] = {0};
    if (isValid(matrix, x + 1, y, rows, columns))
    {
        arr[dir_down] = 1;
        arr[4]++;
    }
    if (isValid(matrix, x - 1, y, rows, columns))
    {
        arr[dir_up] = 1;
        arr[4]++;
    }
    if (isValid(matrix, x, y + 1, rows, columns))
    {
        arr[dir_right] = 1;
        arr[4]++;
    }
    if (isValid(matrix, x, y - 1, rows, columns))
    {
        arr[dir_left] = 1;
        arr[4]++;
    }
    if (arr[4] == 0)
    {
        return -1;
    }

    int a= -1, result=-1;
    if (arr[dir_up] == 1)
    {
        if ((arr[4] == 1))
        {
            a = backtrack(matrix, x - 1, y, rows, columns, dir_up, n_changes, finished);
        }
        else
        {
            a = backtrack(matrix, x - 1, y, rows, columns, dir_up, n_changes+1, finished);
        }
    }
    result = max(a, result);
    if (arr[dir_down] == 1)
    {
        if ((arr[4] == 1))
        {
            a = backtrack(matrix, x + 1, y, rows, columns, dir_down, n_changes, finished);
        }
        else
        {
            a = backtrack(matrix, x + 1, y, rows, columns, dir_down, n_changes+1, finished);
        }
    }
    result = max(a, result);
    if (arr[dir_right] == 1)
    {
        if ((arr[4] == 1))
        {
            a = backtrack(matrix, x, y+1, rows, columns, dir_right, n_changes, finished);
        }
        else
        {
            a = backtrack(matrix, x , y+1, rows, columns, dir_right, n_changes+1, finished);
        }
    }
    result = max(a, result);
    if (arr[dir_left] == 1)
    {
        if ((arr[4] == 1))
        {
            a = backtrack(matrix, x , y-1, rows, columns, dir_left, n_changes, finished);
        }
        else
        {
            a =  backtrack(matrix, x, y-1, rows, columns, dir_left, n_changes+1, finished);
        }
    }
    matrix[x][y] = '.';
    result = max(a, result);
    return result;
}

int main()
{
    int T;
    scanf("%d", &T);
    int rows, columns, guess;
    int start_x, start_y;
    for (int z = 0; z < T; z++)
    {
        scanf("%d %d", &rows, &columns);
        getchar();
        char ** matrix = (char **)malloc(sizeof(char *) * rows);
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = (char *)malloc(sizeof(char) * columns);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                scanf("%c", &matrix[i][j]);
                if (matrix[i][j] == 'M')
                {
                    start_x = i;
                    start_y = j;
                }
            }
            getchar();
            //    printf("%s\n", matrix[i]);
        }
        scanf("%d", &guess);
        bool finished = false;
        int result = backtrack(matrix, start_x, start_y, rows, columns,  none, 0, finished);
        // printf("%d ",result);
        if (result == guess){
            printf("Impressed\n");
        }else{
            printf("Oops!\n");
        }
    }
    return 0;
}

