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
	int m;
	cin >> m;
	int b[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int c[n + m];

	int aa = 0, bb = 0, cc = 0;

	while (aa < n && bb < m) {
		if (a[aa] < b[bb]) {
			c[cc] = a[aa];
			cc++; aa++;
		}
		else {
			c[cc] = b[bb];
			cc++ ; bb++;
		}
	}

	while (aa < n) {
		c[cc] = a[aa];
		aa++; cc++;
	}

	while (bb < m) {
		c[cc] = b[bb];
		bb++; cc++;
	}

	for (int i = 0; i < cc; i++) {
		cout << c[i] << " ";
	}

}