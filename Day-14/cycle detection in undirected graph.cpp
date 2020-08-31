#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<pair<int, int>> gr[N];
int vis[N];

// undirected tree
bool dfs1(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x.first]) {
			bool cycle_insubtree = dfs(x.first, cur);
			if (cycle_insubtree) return true;
		}
		else if (x.first != par) {
			// backedge
			return true;
		}
	}
	return false;
}

// undirected graph
bool dfs2(int cur, int par) {
	vis[cur] = 1;
	bool cycle = false;
	for (auto x : gr[cur]) {
		if (!vis[x.first]) {
			cycle |= dfs(x.first, cur);
		}
		else if (x.first != par) {
			cycle = true;
		}
	}
	return cycle;
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
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	if (dfs(1, 0)) {
		cout << "cycle\n";
	}
	else {
		cout << "no cycle\n";
	}

}