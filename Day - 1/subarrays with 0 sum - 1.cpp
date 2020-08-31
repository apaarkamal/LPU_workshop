#include<bits/stdc++.h>
using namespace std;


int NC2(int n) {
	return (n) * (n - 1) / 2;
}


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

	unordered_map<int, int> mp;

	int pref = 0;
	// for all the subarrays starting at index 0
	mp[0]++;

	for (int i = 0; i < n; i++) {
		pref += a[i];
		mp[pref]++;
	}

	int ans = 0;
	for (auto x : mp) {
		cout << x.first << " " << x.second << '\n';
		ans += NC2(x.second);
	}

	cout << ans;
}