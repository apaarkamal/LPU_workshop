#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code



	// S.insert(10);
	// S.insert(15);
	// S.insert(1);
	// S.insert(5);
	// S.insert(8);

	// // k-th order statistics

	// // log(n)
	// cout << *S.find_by_order(2) << '\n'; // S[k]

	// cout << S.order_of_key(2);

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	new_data_set S;
	int inversions = 0;

	for (int i = 0; i < n; i++) {
		int cnt = S.order_of_key(a[i]);
		inversions += i - cnt;

		cout << i - cnt << " ";

		S.insert(a[i]);
	}

	cout << inversions;

}