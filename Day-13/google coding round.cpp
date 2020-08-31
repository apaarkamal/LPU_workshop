#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

// if a[i] is prime we cant change it

const int N = 1e6 + 500;

int pr[N];
vector<int> primes;

void seive() {
	int i, j;
	for (i = 2; i < N; i++) {
		if (!pr[i]) {
			primes.pb(i);
			for (j = i; j < N; j += i) {
				pr[j]++;
			}
		}
	}
}


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//  code starts
	seive();

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int a[n][2];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (binary_search(primes.begin(), primes.end(), x)) {
				a[i][0] = x;
				a[i][1] = x;
			}
			else {
				int idx = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
				a[i][1] = primes[idx];
				a[i][0] = primes[idx - 1];
			}
		}
		int dp[n][2];
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 2; k++) {
				dp[i][k] = 1;
				for (int j = 0; j < i; j++) {
					if (a[j][0] < a[i][k]) dp[i][k] = max(dp[i][k], dp[j][0] + 1);
					if (a[j][1] < a[i][k]) dp[i][k] = max(dp[i][k], dp[j][1] + 1);
				}
			}
			cout << dp[i][0] << " " << dp[i][1] << '\n';
		}
		int lis = 0;
		for (int i = 0; i < n; i++) {
			lis = max({lis, dp[i][0], dp[i][1]});
		}
		cout << lis << '\n';
	}

}
