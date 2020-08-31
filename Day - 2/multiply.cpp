#include<bits/stdc++.h>
using namespace std;

long long int prime = 5;

// modular multiplication
long long int multiply(long long int a, long long int b) {
	long long int res = 0;

	while (b) {
		// res , a are less than prime

		if (b & 1) res += a, res %= prime;

		a *= 2;
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
	cout << multiply(2, 8);

}