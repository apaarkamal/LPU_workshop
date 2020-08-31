#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code

	int n;
	cin >> n;

	vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};

	int res = 0;

	for (int mask = 1; mask < (1 << (int)prime.size()); mask++) {

		int lcm = 1;
		for (int bit = 0; bit < prime.size(); bit++) {

			if ((mask >> bit) & 1ll) lcm *= prime[bit];

		}
		// cout << lcm << '\n';

		if (__builtin_popcount(mask) % 2) {
			// count of number divisible by lcm
			res += (n / lcm);
		}
		else {
			res -= (n / lcm);
		}

	}
	cout << res;

}