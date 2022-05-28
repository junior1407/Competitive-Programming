#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>



//0 4 5

int dp(vi& arr, vvi& memo, int index, int last_elem) {
    if (index >= arr.size()) {
        return 0;
    }
    if (memo[index][last_elem] != -1) {
        return memo[index][last_elem];
    }
    if (arr[index] <= last_elem) {
        return 0;
    }

    int ans = INT_MIN;
    for (int i = last_elem + 1; i <= arr[index]; i++) {
        ans = max(ans, i + dp(arr, memo, index+1, i));
    }
    memo[index][last_elem] = ans;
    return ans;
}


int solve(vi& arr) {
    //dp with each element [starting_index] [previous_value]
    int max_val = arr[0]; for (int a : arr) { max_val = max(max_val, a);}
    vvi memo (arr.size(), vi(max_val+1, -1));
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        ans = max(ans, dp(arr, memo, i, 0));
    }
    return ans;
}

void test(int expected, int obtained) {
    if (expected == obtained) {
        printf("CORRECT\n");
    }
    else {
        printf("Expected %d, got %d\n", expected, obtained);
    }
}
int main() {

    vi a = {1001, 1000, 9};
    vi b = {7, 4 , 5 , 2, 6, 5};
    test(1999, solve(a));
    test(12, solve(b));
    return 0;
}