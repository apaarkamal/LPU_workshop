#include<bits/stdc++.h>
using namespace std;

string s;
int n;

const int N = 1e4;
const int modul = 1e9 + 7;

int memo[N][35][2];

int dp(int cur, int mod, bool last) {
	if (cur == s.size()) return (mod == 0);
	int end_digit;
	if (memo[cur][mod][last] != -1) return memo[cur][mod][last];
	if (last) end_digit = s[cur] - '0';
	else end_digit = 9;
	int ans = 0;
	for (int digits = 0; digits <= end_digit; digits++) {
		ans += dp(cur + 1, (mod * 10 + digits) % n, last && (digits == end_digit));
		ans %= modul;
	}
	return memo[cur][mod][last] = ans;
}

int give(string t, int m) {
	s = t;
	n = m;
	memset(memo, -1, sizeof(memo));
	return dp(0, 0, 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	// int ans_5 = give("999", 5);
	// int ans_7 = give("999", 7);
	// int ans_35 = give("999", 35);
	// int total_number_till_3_digit = ans_5 + ans_7 - ans_35;

	// int ans1_5 = give("99", 5);
	// int ans1_7 = give("99", 7);
	// int ans1_35 = give("99", 35);
	// int total_number_till_2_digit = ans1_5 + ans1_7 - ans1_35;

	// cout << total_number_till_3_digit - total_number_till_2_digit;

	// cout << give("9344324242342342334234429", 5) -
	//      give("912321312312321312", 5);



}