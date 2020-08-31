#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code

    int n;
    cin >> n;
    int a[n];
    int res[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res[i] = 1;
    }
    stack<int> St;
    for (int i = 0; i < n; i++) {
        while (!St.empty() && a[St.top()] < a[i]) {
            res[i] += res[St.top()];
            St.pop();
        }
        St.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

}