#include<bits/stdc++.h>
using namespace std;

const int N = 100;

vector<int> primes;
void seive() {

	p[0] = p[1] = 0;
	vector<bool> p(N, 1);

	for (int i = 2; i < N; i++) {

		if (p[i] == 0) continue;
		// it has to be a prime number
		if (p[i] == 1) primes.push_back(i);
		// cancel out all the multiples if i
		for (int j = i * i; j < N; j += i) {
			p[j] = 0;
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
	// for (auto x : primes) {
	// 	cout << x << '\n';
	// }

	// if (binary_search(primes.begin(), primes.end(), n)) cout << "Yes";
	// else cout << "No";



}