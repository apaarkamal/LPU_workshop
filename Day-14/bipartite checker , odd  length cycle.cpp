#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int col[N], vis[N];
bool odd_cycle = false;

void dfs(int cur, int par, int temp_col) {
	col[cur] = temp_col;
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x, cur, 3 - temp_col);
		}
		else if (x != par && col[x] == col[cur]) {
			odd_cycle = true;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1, 0, 1);
	if (odd_cycle) cout << "Not bipartite\n";
	else cout << "bipartite";
}