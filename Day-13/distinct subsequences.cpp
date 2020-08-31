#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string s, t;
	vector<vector<int>> memo;
	int dp(int i, int j) {
		if (j == t.size()) return 1;

		if (memo[i][j] != -1) return memo[i][j];

		// not include s[i]
		int ans = 0;
		if (i < s.size()) ans = dp(i + 1, j);

		// include s[i]
		if (i < s.size() && s[i] == t[j]) ans += dp(i + 1, j + 1);

		return memo[i][j] = ans;
	}

	int numDistinct(string s, string t) {
		this->s = s;
		this->t = t;
		memo.resize(s.size() + 1, vector<int>(t.size() + 1, -1));
		return dp(0, 0);
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	string s, t;
	cin >> s >> t;
	Solution H;
	cout << H.numDistinct(s, t);

}