#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		int dp[n][3];
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2 * b[0];

		for (int i = 1; i < n; i++) {
			for (int k = 0; k < 3; k++) {
				dp[i][k] = INT_MAX;
				for (int j = 0; j < 3; j++) {
					if (a[i - 1] + j == a[i] + k) continue;
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + b[i] * k);
				}
			}
		}

		cout << *min_element(dp[n - 1], dp[n - 1] + 3) << '\n';

	}

}