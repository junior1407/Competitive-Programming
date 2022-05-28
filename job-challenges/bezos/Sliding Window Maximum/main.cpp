//https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;


//{1,3,-1,-3,-5,3,6,7};
// 3 -1
// 3 -1 -3 -5
// 5
// 5 3 
// 6
// 7
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> window; // Decreasing.  Max is in window[0], newer elements are in the back.
    vector<int> ans;
    int i = 0, j = 0;
    while (j < nums.size()) {
        //printf("%d, %d\n", i, j);
        //Removing smaller elements to mantain decreasing.
        while (!window.empty() && nums[window.back()] < nums[j]) {
            window.pop_back();
        }

        //Removing out of bounds elements, has to be between i and j
        //printf("%d, %d, %d\n", i, j, (window.front()));
        while(!window.empty() && (window.front()) < i) {
            //printf("POPPED");
            window.pop_front();
        }
        window.push_back(j);

        if (j - i + 1 == k) {
            //printf("pushing %d\n", window.front());
            ans.push_back(nums[window.front()]);
            //printf("%d ", nums[window.front()]);
            i++;
        }
        j++;
        
    }
    return ans;
}

void print(vector<int> a) {
    for (int i = 0; i< a.size(); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test(vector<int> expected, vector<int> received) {
    if (expected == received) {
        printf("SUCCESS\n");
    }
    else {
        printf("\n\n");
        print(expected);
        print(received);
        printf("FAILED\n");
    }
}

int main() {
    vector<int> in1 = {1,3,-1,-3,5,3,6,7};
    int w1 = 3;
    vector<int> ou1 = {3,3,5,5,6,7};

    vector<int> in2 = {1};
    int w2 = 1;
    vector<int> ou2 = {1};

    vector<int> in3 = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int w3=3;
    vector<int> ou3 = {3, 3, 4, 5, 5, 5, 6};

    vector<int> in4 = {1, -1};
    int w4=1;
    vector<int> ou4 = {1, -1};
    test(ou1, maxSlidingWindow(in1, w1));
    test(ou2, maxSlidingWindow(in2, w2));
    test(ou3, maxSlidingWindow(in3, w3));
    test(ou4, maxSlidingWindow(in4, w4));
    return 0;

}
