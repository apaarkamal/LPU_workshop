#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int dep[N], dis[N], sub[N], height[N];
int diameter;

void dfs(int cur, int par) {
	dep[cur] = dep[par] + 1;
	sub[cur] = 1;
	int mx1 = 0, mx2 = 0;
	for (auto x : gr[cur]) {
		if (x != par) {
			dis[x] = dis[cur] + 1;
			dfs(x, cur);
			sub[cur] += sub[x];
			height[cur] = max(height[x] + 1, height[cur]);
			if (height[x] + 1 >= mx1) {
				mx2 = mx1;
				mx1 = height[x] + 1;
			}
			else if (height[x] + 1 >= mx2) {
				mx2 = height[x] + 1;
			}
		}
	}
	diameter = max(diameter, mx1 + mx2);
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
	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " " << dis[i] << " " << dep[i] << " " << height[i] << " " << sub[i] << '\n';
	// }
	cout << diameter;
}