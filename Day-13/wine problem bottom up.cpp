#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int dp[n][n] = {};

	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			int year = n - (r - l + 1) + 1;
			if (l == r) {
				dp[l][r] = a[l] * year;
			}
			else {
				dp[l][r] = max(a[l] * year + dp[l + 1][r], a[r] * year + dp[l][r - 1]);
			}
		}
	}

	cout << dp[0][n - 1];

}