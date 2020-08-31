#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>> costs) {
		if (costs.empty()) return 0;
		int n = costs.size(), m = costs[0].size();
		if (m == 0) return 0;
		int dp[n][m];

		for (int i = 0; i < m; i++) {
			dp[0][i] = costs[0][i];
		}

		for (int i = 1; i < n; i++) {
			pair<int, int> m1, m2;
			m1 = m2 = {INT_MAX, -1};
			for (int k = 0; k < m; k++) {
				if (dp[i - 1][k] <= m1.first) {
					m2 = m1;
					m1 = {dp[i - 1][k], k};
				}
				else if (dp[i - 1][k] <= m2.first) {
					m2 = {dp[i - 1][k], k};
				}
			}

			for (int j = 0; j < m; j++) {
				dp[i][j] = INT_MAX;
				if (m1.second == j) {
					dp[i][j] = m2.first + costs[i][j];
				}
				else {
					dp[i][j] = m1.first + costs[i][j];
				}
			}

		}
		return *min_element(dp[n - 1], dp[n - 1] + m);
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