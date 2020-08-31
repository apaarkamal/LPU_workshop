#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

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

	int pref[n];
	pref[0] = a[0];

	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	int queries;
	cin >> queries;

	while (queries--) {
		int l, r;
		cin >> l >> r;

		// int sum = pref[r] - pref[l] + a[l];

		int sum = pref[r] - (l > 0 ? pref[l - 1] : 0);

		cout << sum << '\n';
	}

}