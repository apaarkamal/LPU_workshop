#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int i, n;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	int right_small[n];
	int left_small[n];
	stack<int> St;
	for (i = 0; i < n; i++) {
		while (!St.empty() && a[St.top()] > a[i]) {
			right_small[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}
	while (!St.empty()) {
		right_small[St.top()] = n;
		St.pop();
	}
	for (i = n - 1; i >= 0; i--) {
		while (!St.empty() && a[St.top()] > a[i]) {
			left_small[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}
	while (!St.empty()) {
		left_small[St.top()] = -1;
		St.pop();
	}
	// for (i = 0; i < n; i++) {
	// 	cout << left_small[i] << " ";
	// } cout << '\n';
	// for (i = 0; i < n; i++) {
	// 	cout << right_small[i] << " ";
	// }

	int max_area = 0;
	for (int i = 0; i < n; i++) {
		int height = a[i];
		int base = (right_small[i] - left_small[i] - 1);
		// cout << base*height << '\n';
		max_area = max(max_area, base * height);
	}
	cout << max_area;

}