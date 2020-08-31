#include<bits/stdc++.h>
using namespace std;

string words[10] = {"", ".,!", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string s;

void nokia(int cur, string ans) {
	if (cur == s.size()) {
		cout << ans << '\n';
		return;
	}
	for (auto x : words[s[cur] - '0']) {
		nokia(cur + 1, ans + x);
	}
	return;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code

	cin >> s;

	nokia(0, "");

}