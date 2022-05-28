#include <bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define MAX_SONGS 1005

class Compare {
    public:
    bool operator() (vi a, vi b) {
        int max_a = max(a[2], a[3]);
        int max_b = max(b[2], b[3]);
        if (max_a > max_b) {
            return true;
        }
        return false;
    }
};

// Check if there is value inside the map != i
int isAvaliable (vi &mapp, int index) {
    for (int i = 0; i < mapp.size(); i++) {
            if (mapp[i] != index) {
                return mapp[i];
            }
    }
    return -1;

}
vi solve(int dur, vi& songs) {
    int target = dur - 30;
    vii mapp(MAX_SONGS);
    for (int i = 0; i < songs.size(); i++) {
        mapp[songs[i]].push_back(i);
    }
    priority_queue <vi, vii, Compare> ans;
    bool no_ans = true;
    for (int i = 0; i < songs.size(); i++) {
        int pair = target - songs[i];
        int pair_pos = isAvaliable(mapp[pair], i);
        if (pair_pos != -1) {
            int a = min(i, pair_pos);
            int b = max(i, pair_pos);
            ans.push({a, b, songs[a], songs[b]});
        }
    }
    vi final_ans = ans.top();
    printf("%d(%d), %d(%d)\n", final_ans[0],final_ans[2] , final_ans[1], final_ans[3]);
    printf("FINISHED\n");
    return final_ans;
}

void evaluate(int dur, vi songs, vi expected) {

    vi ans = solve(dur, songs);
    if (ans[0] ==  expected[0] && ans[1] == expected[1]) {
        printf("CORRECT");
    }
    else {
        printf("INCORRECT");
    }
}
int main() {
    evaluate(90, {1, 10, 25, 25, 35, 60}, {2, 4});
    return 0;
}