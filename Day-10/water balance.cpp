#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define int long long int

int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<pair<int, int>> St;

    for (int i = 0; i < n; i++) {
        St.push({a[i], 1});

        while (St.size() >= 2) {

            pair<int, int> top1 = St.top();
            St.pop();
            pair<int, int> top2 = St.top();
            St.pop();

            if (top2.S * (top1.F + top2.F) < top2.F * (top1.S + top2.S)) {
                //merge
                top1.F += top2.F;
                top1.S += top2.S;
                St.push(top1);
            }
            else {
                St.push(top2);
                St.push(top1);
                break;
            }
        }
    }
    stack<pair<int, int>> St1;
    while (!St.empty()) {
        // cout << St.top().F << " " << St.top().S << '\n';
        St1.push(St.top());
        St.pop();
    }

    double res[n];
    int i = 0;

    while (!St1.empty()) {
        double value = St1.top().F;
        int length = St1.top().S;
        value /= (double)length;
        while (length--) {
            res[i++] = value;
        }
        St1.pop();
    }

    cout << setprecision(10) << fixed;
    for (i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }

}