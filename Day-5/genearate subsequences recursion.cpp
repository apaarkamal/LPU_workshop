#include<bits/stdc++.h>
using namespace std;

void generate_subsequences(string s, string ans) {
	if (s.empty()) {
		cout << ans << '\n';
		return;
	}
	// include it
	generate_subsequences(s.substr(1), ans + s[0]);
	// exclude it
	generate_subsequences(s.substr(1), ans);
	return;
}




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	code
	string s;
	cin >> s;

	generate_subsequences(s, "");




}