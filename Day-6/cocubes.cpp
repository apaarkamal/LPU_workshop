#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int cnt;

void go(int x) {
	if (x > n) return;
	// v.push_back(x);
	cnt++;
	go(x * 10 + 1);
	go(x * 10 + 4);
	go(x * 10 + 9);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	cin >> n;
	go(0);
	v.erase(v.begin());
	// for (auto x : v) cout << x << "\n";
	cout << cnt;
}