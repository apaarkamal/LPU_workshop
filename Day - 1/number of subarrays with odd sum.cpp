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

	int pref = 0;
	// for all the subarrays starting at index 0
	int cnt[2] = {};
	// cnt[0] represents even
	// cnt[1] represents odd
	cnt[0]++;

	int ans = 0;
	for (int i = 0; i < n; i++) {

		pref += a[i];
		pref = abs(pref);
		pref %= 2;

		if (pref == 0) {
			// even
			ans += cnt[1];
		}
		else {
			// odd
			ans += cnt[0];
		}

		cnt[pref]++;
	}

	cout << ans;


}




######

Optimized Code CPP

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen is not needed in this optimized version

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int pref = 0;
    int cnt[2] = {1, 0}; // Initialize cnt[0] to 1 and cnt[1] to 0 since the first element is even.

    int ans = 0;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        pref = abs(pref) % 2;
        ans += cnt[pref ^ 1]; // XOR with 1 toggles between 0 and 1
        cnt[pref]++;
    }

    cout << ans << "\n";
    return 0;
}


#NOTE:
In this optimized version:

We've removed the #ifndef ONLINE_JUDGE part, which is typically used for file I/O and is not needed in an optimized code snippet.
We've added ios_base::sync_with_stdio(false) and cin.tie(nullptr) to make input operations faster.
We've replaced the array a with a vector, which is more flexible and efficient.
We've initialized cnt[0] to 1 and cnt[1] to 0 since the first element is even.
We've used the XOR operator ^ to toggle between 0 and 1, making the code more concise.
We've removed the unnecessary #ifndef ONLINE_JUDGE and freopen lines since they are not required for this code snippet.
These optimizations should make your code more efficient and readable.
