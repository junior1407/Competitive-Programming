#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
int get_n_left_elements(vi& positions, int i) {
    int pos = positions[i];
    int n_left_elements = pos;
    if (i - 1 >= 0) {
        n_left_elements -= positions[i-1] + 1;
    }
    return n_left_elements;
}
int get_n_right_elements(vi& positions, int i, int n) {
    int pos = positions[i];
    int right_bound = n;
    if (i + 1 < positions.size()) {
        right_bound = positions[i+1];
    }
    return right_bound-pos-1;
}
long long solve(vi& positions, int n, char c) {
    long long ans = 0;
    for (int i = 0; i < positions.size(); i++) {
        int left = get_n_left_elements(positions, i) + 1;
        int right = get_n_right_elements(positions, i, n) + 1;
        ans +=  left*right;
    }
    return ans;

}
int uniqueLetterString(string s) {
    map<int, vi> mapp;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        mapp[s[i]].push_back(i);
    }
    long long ans = 0;
    for (auto it = mapp.begin(); it != mapp.end(); it++) {
        vi& positions = it->second;
        ans += solve(positions, n, it->first);
    }
        printf("ans = %lld \n", ans);
        //XXL
        //X:  0, 1
        //L:  2
        //0st case:    X_
        // 1st case:   _X_
        // 2nd case:  (start, 2) = (0,2), (1,2), (2,2)

    return ans;
}

void checkAnswer(int test_case, int answer, int expected) {
    printf("Case %d ", test_case);
    if (answer == expected) {
        printf("CORRECT\n");
    }
    else {
        printf("INCORRECT\n");
    }
}

int main(){
    checkAnswer(1, uniqueLetterString("abc"), 10);
    checkAnswer(2, uniqueLetterString("leetcode"), 92);
}