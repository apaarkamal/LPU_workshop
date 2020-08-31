#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string s1, s2, s3;
	vector<vector<int>> memo;
	int dp(int i, int j, int k) {
		if (i == s1.size() && j == s2.size() && k == s3.size()) return 1;
		if (k == s3.size()) return false;

		if (memo[i][j] != -1) return memo[i][j];

		int can = 0;
		// either i matches k
		if (i < s1.size() && s1[i] == s3[k]) {
			can |= dp(i + 1, j, k + 1);
		}
		// or j matches k
		if (j < s2.size() && s2[j] == s3[k]) {
			can |= dp(i, j + 1, k + 1);
		}
		return memo[i][j] = can;
	}

	bool isInterleave(string s1, string s2, string s3) {
		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;
		memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
		return dp(0, 0, 0);
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution H;
	cout << H.isInterleave(s1, s2, s3);

}