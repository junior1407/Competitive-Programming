// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/superman-celebrates-diwali

#include <bits/stdc++.h>

using namespace std;

int n_buildings, height, loss;
vector<vector<int>> arr;
vector<int> hashuh;

int dp() {
    for (int curr_floor = 0; curr_floor < height; curr_floor++) {
        hashuh[curr_floor] = -1;
        for (int curr_building = 0; curr_building < n_buildings; curr_building++) {
            if ((curr_floor - loss >= 0) && (curr_floor - 1 >= 0)) {
                arr[curr_building][curr_floor] += max(arr[curr_building][curr_floor - 1], hashuh[curr_floor - loss]);
            } else if (curr_floor > 0) {
                arr[curr_building][curr_floor] +=arr[curr_building][curr_floor - 1];
            }
            hashuh[curr_floor] = max(hashuh[curr_floor], arr[curr_building][curr_floor]);
        }
    }
    return hashuh[height-1];

}

int main() {
    int x, y;
    scanf("%d %d %d", &n_buildings, &height, &loss);
    arr.resize(n_buildings);
    for (int i = 0; i < n_buildings; i++) {
        arr[i].resize(height);
    }
    hashuh.resize(height + 1);
    for (int i = 0; i < n_buildings; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            scanf("%d", &y);
            arr[i][y - 1]++;
        }
    }

    printf("%d\n", dp());

    return 0;
}
