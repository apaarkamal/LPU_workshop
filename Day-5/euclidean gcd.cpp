#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0) return a + b;
	else return gcd(b % a, a);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code

	int a, b;
	cin >> a >> b;

	// cout << __gcd(a, b);

	cout << gcd(a, b);

}