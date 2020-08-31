#include<bits/stdc++.h>
using namespace std;

long long int prime = 1e9 + 7;

const int N = 1e5;

long long int fact[N];

long long int exponentiation(long long int a, long long int b) {
	long long int res = 1;

	while (b) {
		// res , a are less than prime

		if (b & 1) res *= a, res %= prime;

		a *= a;
		a %= prime;

		b /= 2;
	}
	return res;
}

long long int inv(int a) {
	return exponentiation(a, prime - 2);
}

void calculate_factorial() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % prime;
	}
}

// nCr % prime
long long int NCR(int n, int r) {
	long long int res = fact[n];
	res *= inv(fact[r]); res %= prime;
	res *= inv(fact[n - r]); res %= prime;
	return res;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	calculate_factorial();
	cout << NCR(10, 2);

}