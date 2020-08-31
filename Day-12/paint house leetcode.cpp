#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> costs) {
        int n = costs.size(), m = 3;
        if (n == 0) return 0;
        int dp[n][m];

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                // filling ith house with jth colour
                // k is the colour of previous house
                dp[i][j] = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], costs[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }
        return *min_element(dp[n - 1], dp[n - 1] + 3);
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code
    Solution H;
    cout << H.minCost({{17, 2, 17}, {16, 16, 5}, {14, 3, 19}});

}