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

	// previous best ending is MSS ending at index (i-1)
	int prev_best_ending = 0, cur_best_ending = 0, ans = 0;

	int pos = -1;

	for (int i = 0; i < n; i++) {

		if (prev_best_ending < 0) prev_best_ending = 0;
		cur_best_ending = prev_best_ending + a[i];

		if (cur_best_ending > ans) {
			ans = cur_best_ending;
			pos = i;
		}

		prev_best_ending = cur_best_ending;

	}

	cout << ans << '\n';

	int sum = 0;
	for (int i = pos; i >= 0; i--) {
		sum += a[i];
		if (sum == ans) {
			cout << "subarray from " << i << " " << pos << '\n';
			break;
		}
	}

}





