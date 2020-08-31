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

	int pref = 0;
	// for all the subarrays starting at index 0
	int cnt[2] = {};
	// cnt[0] represents even
	// cnt[1] represents odd
	cnt[0]++;

	int ans = 0;
	for (int i = 0; i < n; i++) {

		pref += a[i];
		pref = abs(pref);
		pref %= 2;

		if (pref == 0) {
			// even
			ans += cnt[1];
		}
		else {
			// odd
			ans += cnt[0];
		}

		cnt[pref]++;
	}

	cout << ans;


}