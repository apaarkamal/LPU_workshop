#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> cost;
	vector<vector<int>> memo;
	int dp(int cur, int col) {
		if (cur == cost.size()) return 0;
		int ans = INT_MAX;
		if (memo[cur][col] != -1) return memo[cur][col];
		for (int next_col = 0; next_col < 3; next_col++) {
			if (next_col != col) {
				ans = min(ans, dp(cur + 1, next_col) + cost[cur][col]);
			}
		}
		return memo[cur][col] = ans;
	}

	int minCost(vector<vector<int>> costs) {
		cost = costs;
		memo.resize(cost.size(), vector<int>(3, -1));
		return min({dp(0, 0), dp(0, 1), dp(0, 2)});
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