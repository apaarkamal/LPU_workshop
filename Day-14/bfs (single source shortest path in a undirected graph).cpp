#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];

vector<int> bfs(int source) {
	vector<int> dis(N, -1);

	queue<int> Q;
	Q.push(source);
	dis[source] = 0;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (auto x : gr[cur]) {
			if (dis[x] == -1) {
				dis[x] = dis[cur] + 1;
				Q.push(x);
			}
		}
	}
	return dis;
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
	vector<int> dis = bfs(6);

	for (int i = 1; i <= n; i++) {
		cout << i << " " << dis[i] << '\n';
	}

}