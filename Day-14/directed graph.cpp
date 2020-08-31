#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> gr[N];
int vis1[N];// original visited
int vis2[N];// in call stack

void dfs(int cur, int par, bool &cycle) {
	vis1[cur] = 1;
	vis2[cur] = 1;

	for (auto x : gr[cur]) {
		if (!vis1[x]) {
			dfs(x, cur, cycle);
		}
		else if (x != par && vis2[x] == 1) {
			// backedge
			cycle = true;
		}
	}
	vis2[cur] = false;
	return;
}

int vis[N];
// 0 mmeans not visited
// 1- visited and in call stack
// 2- visited and not in call stack

void dfs(int cur, int par, bool &cycle) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis1[x]) {
			dfs(x, cur, cycle);
		}
		else if (x != par && vis[x] == 1) {
			// backedge
			cycle = true;
		}
	}
	vis[cur] = 2;
	return;
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
	}

	bool cycle = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis1[i]) dfs(i, 0, cycle);
	}

	if (cycle) cout << "cycle";
	else cout << "no cycle";

}