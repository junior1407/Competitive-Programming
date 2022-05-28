#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define dqi deque<int>

// 6  4  

int findMaximumSustainableClusterSize(vector<int> processingPower, vector<int> bootingPower, long powerMax){
    int n = processingPower.size();
    dqi max_booting;
    int sum_processing = 0;
    int i=0, j=0, ans = 0;
    while(i < n && j < n) {
        sum_processing += processingPower[j];
        // Clear smaller elements from deque
        while(!max_booting.empty() && bootingPower[j] > bootingPower[max_booting.back()]) {
            max_booting.pop_back();
        }
        
        // Clear out of bounds elements
        while(!max_booting.empty() && max_booting.front() < i ) {
            max_booting.pop_front();
        }

        max_booting.push_back(j);

        // Check if maximum was exceed, then i++
        while(i <= j && !max_booting.empty() && ((bootingPower[max_booting.front()]) + (j-i+1) * sum_processing) > powerMax ) {
            sum_processing -= processingPower[i];
            if (max_booting.front() == i) {
                max_booting.pop_front();
            }
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }
    return ans;
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
