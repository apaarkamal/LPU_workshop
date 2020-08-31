#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n, m;
	cin >> n >> m;
	int a[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}


	int ans = 0;
	// O(n^6)
	// for (int l1 = 0; l1 < n; l1++) {
	// 	for (int r1 = 0; r1 < m; r1++) {

	// 		for (int l2 = l1; l2 < n; l2++) {
	// 			for (int r2 = r1; r2 < m; r2++) {


	// 				int sum = 0;
	// 				for (int i = l1; i <= l2; i++) {
	// 					for (int j = r1; j <= r2; j++) {

	// 						sum += a[i][j];

	// 					}
	// 				}

	// 				ans = max(ans, sum);

	// 			}
	// 		}

	// 	}
	// }


	int pref[n][m];
	pref[0][0] = a[0][0];


	// fill up the first row
	for (int j = 1; j < m; j++) {
		pref[0][j] = pref[0][j - 1] + a[0][j];
	}

	// first column
	for (int i = 1; i < n; i++) {
		pref[i][0] = pref[i - 1][0] + a[i][0];
	}

	// O(n^2)
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1]
			             - pref[i - 1][j - 1] + a[i][j];
		}
	}

	// O(n^4)
	for (int l1 = 0; l1 < n; l1++) {
		for (int r1 = 0; r1 < m; r1++) {

			for (int l2 = l1; l2 < n; l2++) {
				for (int r2 = r1; r2 < m; r2++) {

					int sum = pref[l2][r2];

					if (r1 > 0) sum -= pref[l2][r1 - 1];

					if (l1 > 0 ) sum -= pref[l1 - 1][r2];

					if (l1 > 0 && r1 > 0) sum += pref[l1 - 1][r1 - 1];

					ans = max(ans, sum);

				}
			}

		}
	}
	cout << ans << '\n';

}