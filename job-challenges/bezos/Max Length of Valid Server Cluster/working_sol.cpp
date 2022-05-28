#include <bits/stdc++.h>
using namespace std;

int findMaximumSustainableClusterSize(vector<int> processingPower, vector<int> bootingPower, long powerMax){
    int n = processingPower.size();
    int i = 0;
    int j = 0;
    
    deque<vector<int>> q;
    long sum = 0;
    int ans = 0;
    while(j < n){
        sum += processingPower[j];
        while(!q.empty() && q.back()[0] <= bootingPower[j]){
            q.pop_back();
        }
        q.push_back({bootingPower[j], j});  
        
        while(i <= j and q.front()[0] + sum*(j-i+1) > powerMax){
            if (q.front()[1] == i){
                q.pop_front();
            }
            sum -= processingPower[i];
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
        
    }
    
    return ans;
}
int main() {
    vector<int> processingPower{4,1,4,5,3}, bootingPower{8,8,10,9,12};
    long powerMax = 1;
    
    cout << findMaximumSustainableClusterSize(processingPower, bootingPower, powerMax);
}