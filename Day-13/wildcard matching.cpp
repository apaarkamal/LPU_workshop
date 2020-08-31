#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	string s, p;
	vector<vector<int>> memo;
	int dp(int i, int j) {

		if (i == s.size() && j == p.size()) return 1;
		if (j == p.size()) return false;

		if (memo[i][j] != -1) return memo[i][j];

		int can = 0;
		// both characters are equal
		if (i < s.size() && s[i] == p[j]) {
			can |= dp(i + 1, j + 1);
		}
		// matches '?' with a character
		if (p[j] == '?' && i < s.size()) {
			can |= dp(i + 1, j + 1);
		}
		// "*"
		if (p[j] == '*') {
			// empty sequence
			can |= dp(i, j + 1);
			// '*' matches the given character
			if (i < s.size()) can |= dp(i + 1, j);
		}
		return memo[i][j] = can;
	}

	bool isMatch(string s, string p) {
		this->s = s;
		this->p = p;
		memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
		return dp(0, 0);
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	string s1, s2;
	cin >> s1 >> s2;
	Solution H;
	cout << H.isMatch(s1, s2);
}