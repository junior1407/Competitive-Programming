#include <bits/stdc++.h>

using namespace std;

#define vi vector<int> 
#define vvi vector<vector<int>>


vvi solve(vvi &forward, vvi &returning, int target) {
    sort(forward.begin(), forward.end(), [](vi a, vi b) {return a[1] < b[1];});
    sort(returning.begin(), returning.end(), [](vi a, vi b) {return a[1] >= b[1];});

    vvi ans;
    int best_sum;
    int a_pos = 0;
    int b_pos = 0;

   //3,5,7,10
   //5,4,3, 2
    while (a_pos < forward.size() && b_pos < returning.size()) {
       // printf("%d %d\n", a_pos, b_pos);
        int curr_sum = forward[a_pos][1] + returning[b_pos][1];
       // printf("Check 0\n");
        if (curr_sum <= target) {
            if ((!ans.empty() && curr_sum > best_sum) || ans.empty()) {
                ans.clear();
                best_sum = curr_sum;
            }
            //printf("Check 1\n");
            if (curr_sum >= best_sum) {
                ans.push_back({forward[a_pos][0], returning[b_pos][0]});
            }
            // Check for next b's.
            for (int i = b_pos + 1; i < returning.size() &&
                returning[i][1] == returning[b_pos][1] ; i++) {
                //    printf("I am at %d \n", i);
                ans.push_back({forward[a_pos][0], returning[i][0]});
            }
            a_pos++;
        }
        else if (curr_sum > target) {
            b_pos++;
        }
    }

    return ans;
}

void evaluate(vvi forward, vvi returning, int target) {
    printf("New test case\n");
    vvi ans = solve(forward, returning, target);
    for (vi &a : ans) {
        printf("%d, %d\n", a[0], a[1]);
    }
}

int main()
{

    evaluate({{1, 2}, {2, 4}, {3,6}}, {{1,2}}, 7);
    evaluate({{1,3}, {2,5}, {3, 7}, {4, 10}}, {{1,2}, {2,3}, {3,4}, {4,5}}, 10);
    return 0;
}


/*
Input:
Max travel distance 10000
Forward route [1, 3000], [2, 5000], [3, 7000], [4, 10000]
returning [1, 2000], [2, 3000], [3, 4000] , [4, 5000]


3,5,7,10
5,4,3, 2

(5,5), (7, 3)
*/