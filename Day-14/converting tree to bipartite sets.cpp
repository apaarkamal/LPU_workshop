#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int dep[N], dis[N], sub[N], height[N];

void dfs(int cur, int par) {
	for (auto x : gr[cur]) {
		if (x != par) {
			dis[x] = dis[cur] + 1;
			dfs(x, cur);
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1, 0);
	set<int> S[2];
	for (int i = 1; i <= n; i++) {
		S[dis[i] % 2].insert(i);
	}
}