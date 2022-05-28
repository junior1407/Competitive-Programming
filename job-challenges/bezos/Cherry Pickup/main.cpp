#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>


struct DP{
    int mapp[71][71][71];
};
typedef struct DP dp_t;


bool possible(int x, int y, int max_x, int max_y) {
    return x >= 0 && x <=max_x && y >=0 && y <=max_y;
}

int solve(dp_t * my_dp, vvi& grid, int x, int y1, int y2, int max_x, int max_y) {
    if (!(possible(x, y1, max_x, max_y) && possible(x, y2, max_x, max_y))) {
        return INT_MIN;
    }
    if (my_dp->mapp[x][y1][y2] != -1) {
        return my_dp->mapp[x][y1][y2];
    }
    int sum = y1 == y2 ? grid[x][y1] : grid[x][y1] + grid[x][y2];
    if (x == max_x) {
        my_dp->mapp[x][y1][y2] = sum;
        return sum;
    }
    sum += max({
        solve(my_dp, grid, x+1, y1-1, y2-1, max_x, max_y),
        solve(my_dp, grid, x+1, y1-1, y2, max_x, max_y),
        solve(my_dp, grid, x+1, y1-1, y2+1, max_x, max_y),
        solve(my_dp, grid, x+1, y1, y2-1, max_x, max_y),
        solve(my_dp, grid, x+1, y1, y2, max_x, max_y),
        solve(my_dp, grid, x+1, y1, y2+1, max_x, max_y),
        solve(my_dp, grid, x+1, y1+1, y2-1, max_x, max_y),
        solve(my_dp, grid, x+1, y1+1, y2, max_x, max_y),
        solve(my_dp, grid, x+1, y1+1, y2+1, max_x, max_y),
    });
    my_dp->mapp[x][y1][y2] = sum;
    return sum;
}

int cherryPickup(vvi& grid) {
    dp_t my_dp;
    memset(my_dp.mapp, -1, sizeof(my_dp.mapp));
    int height = grid.size();   
    int width = grid[0].size();
    return solve(&my_dp, grid, 0, 0, width-1, height-1, width-1);
}

void assertt(int received, int expected) {
    if (received != expected) {
        printf("%d != %d\n", received, expected);
        printf("IN");
    }
    printf("CORRECT\n");
}
int main() {
    vvi t1 ={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    vvi t2 = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    assertt(cherryPickup(t1), 24);
    assertt(cherryPickup(t2), 28);
    
    return 0;
}