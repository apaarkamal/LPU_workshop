#include<bits/stdc++.h>
using namespace std;

const int N = 100000;

int n;
int a[N];
vector<vector<int>> memo;

int dp(int l, int r, int year) {

    if (l > r) return 0;

    if (memo[l][r] != -1) return memo[l][r];

    int profit = 0;
    // either pick left
    profit = max(profit, (a[l] * year) + dp(l + 1, r, year + 1));
    // or pick right
    profit = max(profit, (a[r] * year) + dp(l, r - 1, year + 1));

    return memo[l][r] = profit;

}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memo.resize(n, vector<int>(n, -1));
    cout << dp(0, n - 1, 1);
}