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

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1]
			             - pref[i - 1][j - 1] + a[i][j];
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << pref[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }

	int q;
	cin >> q;
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		int sum = pref[l2][r2];

		if (r1 > 0) sum -= pref[l2][r1 - 1];

		if (l1 > 0 ) sum -= pref[l1 - 1][r2];

		if (l1 > 0 && r1 > 0) sum += pref[l1 - 1][r1 - 1];

		cout << sum << '\n';

	}


}