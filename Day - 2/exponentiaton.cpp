#include<bits/stdc++.h>
using namespace std;

long long int prime = 1e9 + 7;

// modular exponentiation
long long int power(long long int a, long long int b) {
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

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	cout << power(2, 8);

}