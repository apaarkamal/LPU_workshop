#include<bits/stdc++.h>
using namespace std;

int place_cows(int a[], int n, int d) {

	int cows = 1, prev = a[0];

	for (int cur = 1; cur < n; cur++) {
		if ((a[cur] - prev) >= d) cows++, prev = a[cur];
	}

	return cows;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int t;
	cin >> t;
	while (t--) {

		int n, c;
		cin >> n >> c;
		int a[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		// for (int d = 1; d <= (a[n - 1] - a[0]); d++) {
		// 	int cows = place_cows(a, n, d);
		// 	cout << d << " " << cows << '\n';
		// }

		int left = 0, right = a[n - 1] - a[0];
		// minimum distance between two cows
		// and maximum distance betweem two cows

		int ans = 0;

		while (left <= right) {

			int mid = (left + right) / 2;
			// number of cows i can place if the distance
			// is at least mid
			int cows_at_mid = place_cows(a, n, mid);

			if (cows_at_mid >= c) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}

		}

		cout << ans << '\n';


	}

}