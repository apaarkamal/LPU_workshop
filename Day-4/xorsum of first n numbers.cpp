#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code

	// int ans = 0;
	// for (int i = 0; i < 20; i++) {
	// 	ans = ans ^ i;
	// 	cout << i << " -> " << ans << '\n';
	// }

	int n;
	cin >> n;

	int rem = n % 4;

	if (rem == 0) cout << n << '\n';
	else if (rem == 1) cout << 1 << '\n';
	else if (rem == 2) cout << n + 1 << '\n';
	else cout << 0 << '\n';

}