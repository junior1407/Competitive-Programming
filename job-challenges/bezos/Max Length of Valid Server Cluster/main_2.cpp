#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define dqi deque<int>



// 3 2 4
// Max(bootPower[i...j]) + Sum(processPower[i....j]) * length of subArray.
int findMaximumSustainableClusterSize(vector<int> processingPower, vector<int> bootingPower, long powerMax){
    int sum_processing = 0;
    int i = 0, j = 0;
    dqi max_deque;
    int best_ans = 0;
    int n = processingPower.size();
    while (i < n && j < n) {
        // Remove smaller booting
        while(!max_deque.empty() && bootingPower[max_deque.back()] < bootingPower[j]) {
            max_deque.pop_back();
        }
        // Remove out of bounds booting
        while(!max_deque.empty() && max_deque.front() < i) {
            max_deque.pop_front();
        }
        max_deque.push_back(j);
        sum_processing += processingPower[j];
        while ((i <= j) && (!max_deque.empty()) && (sum_processing + (bootingPower[max_deque.front()]*(j-i + 1)) > powerMax)) {
            sum_processing -= processingPower[i];
            if (i == max_deque.front()) {
                max_deque.pop_front();
            }
            i++;
        }
        best_ans = max(best_ans, j - i + 1);
        printf("%d, %d\n", i, j);
        j++; 
    }
    return best_ans;
}

void test(int expected, int received) {
    if (expected == received) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILED\n");
    }
}

int main() {

    vi processingPower1 = {2, 1, 3, 4, 5};
    vi bootingPower1 = {3, 6, 1, 3, 4};
    test(3, findMaximumSustainableClusterSize(processingPower1, bootingPower1, 25));

    processingPower1 = {1,2,3,4};
    bootingPower1 = {1,2,3,4};
    test(2, findMaximumSustainableClusterSize(processingPower1, bootingPower1, 10));

    processingPower1 = {1,1,1,1};
    bootingPower1 = {2,3,4,2};
    test(2, findMaximumSustainableClusterSize(processingPower1, bootingPower1, 8));
    return 0;
}
