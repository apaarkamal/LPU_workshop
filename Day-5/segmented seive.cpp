#include<bits/stdc++.h>
using namespace std;

const int N = 31700;

vector<int> primes;

void seive() {

	vector<int> p(N, 1);

	for (int i = 2; i < N; i++) {
		if (p[i] == 0) continue;
		primes.push_back(i);
		for (int j = i * i; j < N; j += i) {
			p[i] = 0;
		}
	}

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code

	seive();
	int t;
	cin >> t;
	while (t--) {

		int l, r;
		cin >> l >> r;

		vector<int> p(r - l + 1, 1);

		for (auto prime : primes) {

			if (prime * prime > r) break;
			// now my prime is less than sqrt(r)

			// calculate start
			int start = (l / prime) * prime;
			if (prime >= l) start = prime * 2;

			// mapping l->0
			// mapping l+1->1

			for (int i = start; i <= r; i += prime) {
				if (i >= l) p[i - l] = 0;
			}

		}

		for (int i = l; i <= r ; i++) {
			if (p[i - l] == 1 && i != 1) {
				cout << i << '\n';
			}
		}
		cout << '\n';

	}

}