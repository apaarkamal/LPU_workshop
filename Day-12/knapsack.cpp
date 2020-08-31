#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

// O(m*n)
int dp(int cur, int weight, int n, int val[], int w[]) {

	if (cur == n) return 0;

	if (memo[cur][weight] != -1) return memo[cur][weight];

	int profit = 0;
	// not include
	profit = dp(cur + 1, weight, n, val, w);
	// include
	if (w[cur] <= weight) {
		profit = max(profit, dp(cur + 1, weight - w[cur], n, val, w) + val[cur]);
	}

	return memo[cur][weight] = profit;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n;
	cin >> n;
	int val[n];
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	int w[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	int m;
	cin >> m;

	memo.resize(n + 1, vector<int>(m + 1, -1));

	cout << dp(0, m, n, val, w);
}