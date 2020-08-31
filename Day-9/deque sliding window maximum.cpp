#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n, k;
	cin >> n >> k;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	deque<int> Q;
	// Q in decreasing order
	for (int i = 0; i < k; i++) {
		while (!Q.empty() && a[Q.back()] <= a[i]) Q.pop_back();
		Q.push_back(i);
	}
	cout << a[Q.front()] << " ";

	for (int i = k; i < n; i++) {
		// remove the out of bound element
		if (Q.front() == i - k) Q.pop_front();

		while (!Q.empty() && a[Q.back()] <= a[i]) Q.pop_back();
		Q.push_back(i);
		cout << a[Q.front()] << " ";
	}



}