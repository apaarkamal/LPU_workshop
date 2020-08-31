#include<bits/stdc++.h>
using namespace std;

// O(sqrt(n))
vector<pair<int, int>> factorisation(int n) {
	vector<pair<int, int>> res;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			// i is a prime number

			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}

			res.push_back({i, cnt});
		}
	}

	if (n > 1) {
		res.push_back({n, 1});
	}

	return res;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n;
	cin >> n;

	vector<pair<int, int>> factors = factorisation(n);

	for (auto x : factors) {
		cout << x.first << " " << x.second << '\n';
	}

}