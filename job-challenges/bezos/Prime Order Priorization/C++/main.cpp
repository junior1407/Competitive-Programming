#include <bits/stdc++.h>

using namespace std;

pair<string, string> split_space(string s) {
    int space_pos = s.find(" ");
    string id = s.substr(0, space_pos);
    string metadata = s.substr(space_pos+1);
    return {id, metadata};
}
void split_orders(vector<string>& orders, vector<pair<string, string>> &primes, 
                vector<pair<string, string>> &non_primes) {
    for (string &order: orders) {
        pair<string, string>  id_metadata = split_space(order);
        if (isdigit(id_metadata.second[0])) {
            non_primes.push_back(id_metadata);
        }
        else {
            primes.push_back(id_metadata);
        }
    }
}

vector<string> join_ans(vector<pair<string, string>> &primes, 
                        vector<pair<string, string>> &non_primes) {
    vector<string> ans;
    for (auto &s : primes) { ans.push_back(s.first + " " + s.second);}
    for (auto &s : non_primes) { ans.push_back(s.first + " " + s.second);}
    return ans;
}


int cmp_str(string a, string b) {
    int min_length = min(a.size(), b.size());
    int pos;
    for (pos = 0; pos < min_length; pos++) {
        if (a[pos] == b[pos]) {
            continue;
        }
        if (a[pos] != b[pos]) {
            break;
        }
    }
    //Same prefix
    if (pos == min_length) {
        if (a.size() == b.size()) {
            return 0;
        }
        return a.size() < b.size() ? -1 : 1;
    }
    return a[pos] < b[pos] ? -1 : 1;
}

bool comp(pair<string, string> a, pair<string, string> b) {
    int res = cmp_str(a.second, b.second);
    if (res == -1) {
        return true;
    }
    if (res == 1) {
        return false;
    }
    res = cmp_str(a.first, b.first);
    if (res == -1) {
        return true;
    }
    return false;
}
vector<string> solve(vector<string>& orders) {
    vector<pair<string, string>> primes, non_primes;
    split_orders(orders, primes, non_primes);  
    sort(primes.begin(), primes.end(), comp);
    return join_ans(primes, non_primes);
}

int main () {
    int t;scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        getchar();
        vector<string> orders;
        string s;
        while(n--) {
            getline(cin, s);
            orders.push_back(s);
        }
        vector<string> ans = solve(orders);
        for (auto &a : ans) {
            cout << a << endl;
        }
    }
    return 0;
}