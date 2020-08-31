#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string s;
	vector<int> memo;
	vector<vector<int>> memo1;
	bool is_palindrome(int l, int r) {
		if (l == r) return true;
		if (r == l + 1) return (s[l] == s[r]);
		if (memo1[l][r] != -1) return memo1[l][r];
		return memo1[l][r] = ((s[l] == s[r]) && is_palindrome(l + 1, r - 1));
	}
	int dp(int cur) {
		if (cur == s.size()) return 0;
		if (memo[cur] != -1) return memo[cur];
		int ans = s.size();
		for (int last = cur; last < s.size(); last++) {
			// if s[cur....last] is a palindrome
			if (is_palindrome(cur, last)) {
				ans = min(ans, 1 + dp(last + 1));
			}
		}
		return memo[cur] = ans;
	}
	int minCut(string s) {
		this->s = s;
		memo.resize(s.size(), -1);
		memo1.resize(s.size(), vector<int>(s.size(), -1));
		return dp(0) - 1;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	string s;
	cin >> s;
	Solution H;
	cout << H.minCut(s);

}