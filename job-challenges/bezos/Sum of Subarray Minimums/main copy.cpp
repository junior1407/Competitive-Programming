//https://leetcode.com/problems/sum-of-subarray-minimums/
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

void print(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
void printv(vi arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
}



1
3
// 3 1 2 4
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int next_lesser_eq[n], prev_lesser[n];
    
    stack<int> stc; stc.push(0);
    for (int i = 1; i < n; i++) {
        // Pop bigger elements
        while() {

        }


    }
// Ao empilhar com pop


}
void test(int calc, int expected) {
    if (calc==expected) {
        printf("SUCCESS\n");
    }
    else {
        printf("GOT %d, expected %d\n", calc, expected);
    }
}

int main() {
    vi a1 = {3,1,2,4};
    vi a2 = {11,81,94,43,3};
    vi a3 = {1, 5, 1};
    test(sumSubarrayMins(a1), 17);
    test(sumSubarrayMins(a2), 444);
    test(sumSubarrayMins(a3), 10);
    return 0;
}