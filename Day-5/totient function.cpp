#include<bits/stdc++.h>
using namespace std;

const int N = 100;

void seive() {

	vector<int> p(N, 0);
	vector<int> tot(N);

	for (int i = 0; i < N; i++) {
		tot[i] = i;
	}

	for (int i = 2; i < N; i++) {
		if (p[i] > 0) continue;
		// i has  to be a prime now
		for (int j = i; j < N; j += i) {
			p[j]++;
			tot[j] *= (i - 1);
			tot[j] /= i;
		}
	}

	for (int i = 2; i < N; i++) {
		cout << i << " " << tot[i] << '\n';
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	seive();
	//




}