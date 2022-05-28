#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pqi priority_queue<vector<int>>
// {id, value}


bool isPossible(vi a, vi b, int target) {
    return b[1] + a[1] <= target;
}

vector<int> optimal(vector<vector<int>>& a, vector<vector<int>>& b, int target)
{
    
    sort(a.begin(), a.end(), 
        [](vector<int> &left, vector<int> &right){ return left[1] < right[1];});
    sort(b.begin(), b.end(), 
        [](vector<int> &left, vector<int> &right){ return left[1] >= right[1];});

    // 1 2 3 4 5
    // 10 9 8 7
    pqi ans;
    int a_pos = 0;
    int b_pos = 0;

    vi best_pair = {-1, -1};
    int best_sum = -1;

    int curr_sum;
    while (a_pos < a.size() && b_pos < b.size()) {
        curr_sum = a[a_pos][1] + b[b_pos][1];
        // If curr_sum is acceptable, then use it. Only use it if the best is empty or if it is
        // better than the previous best.
        if (curr_sum <= target && (best_pair[0] == -1 ||(best_pair[0] != -1 && curr_sum > best_sum))){
            best_pair[0] = a_pos;
            best_pair[1] = b_pos;
            best_sum = curr_sum;
        }

        if (curr_sum == target) {
            break;
        }
        if (curr_sum < target) {
            a_pos++;
        }
        else {
            b_pos++;
        }
    }
    return best_pair;
}

void test(vector<vector<int>> a, vector<vector<int>> b, int target)
{
    vector<int> res = optimal(a, b, target);
    int a_pos = res[0], b_pos = res[1];
    int a_value = a[a_pos][1];
    int b_value = b[b_pos][1];
    printf("A(pos=%d, value=%d), B(pos=%d, value =%d)\n", a_pos, a_value , b_pos, b_value);
}

int main()
{
    test({{1, 2}, {2, 4}, {3, 6}}, {{1, 2}}, 7);
    test({{1, 3}, {2, 5}, {3, 7}, {4, 10}}, {{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 10);
    test({{1, 8}, {2, 7}, {3, 14}}, {{1, 5}, {2, 7}, {3, 14}}, 20);
    return 0;
}