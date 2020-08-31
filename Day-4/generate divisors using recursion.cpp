#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> factors;
int n;

void generate_divisors(int index, int ans) {

	if (index == n) {

		cout << ans << '\n';
		return;
	}

	int prime = factors[index].first;
	int power = factors[index].second;

	for (int i = 0; i <= power; i++) {

		generate_divisors(index + 1, ans * pow(prime, i));

	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	cin >> n;

	factors.resize(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		factors[i] = {x, y};
	}

	generate_divisors(0, 1);

}