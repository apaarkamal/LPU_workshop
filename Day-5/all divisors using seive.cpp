#include<bits/stdc++.h>
using namespace std;

const int N = 100;

void seive() {

	vector<int> p(N, 0);

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			// i is divisor of j
			// j is multiple of i
			p[j]++;
		}
	}

	for (int i = 1; i < N; i++) {
		cout << i << "\t" << p[i] << '\n';
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	seive();




}