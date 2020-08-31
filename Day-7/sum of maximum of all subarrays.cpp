#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left_max[n], right_max[n];
	for (int i = 0; i < n; i++) {
		left_max[i] = -1;
		right_max[i] = n;
	}

	stack<int> St;
	for (int i = 0; i < n; i++) {
		while (!St.empty() &&  a[i] > a[St.top()]) {
			right_max[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}
	while (!St.empty()) St.pop();
	for (int i = n - 1; i >= 0; i--) {
		while (!St.empty() &&  a[i] > a[St.top()]) {
			left_max[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}
	while (!St.empty()) St.pop();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = i - left_max[i];
		int right = right_max[i] - i;
		int total_subaarays = left * right;
		ans += total_subaarays * a[i];
	}
	cout << ans;
}