#include<bits/stdc++.h>
using namespace std;

// generate all susets of a and push in subset
void generatesubsets(vector<int> a, vector<int> &subset) {
    int n = a.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int bit = 0; bit < n; bit++) {
            if ((mask >> bit) & 1) {
                sum += a[bit];
            }
        }
        subset.push_back(sum);
    }
}



int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code

    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> leftsubsetsum, rightsubsetsum;

    vector<int> left(a.begin() , a.begin() + n / 2);
    vector<int> right(a.begin() + n / 2, a.end());

    generatesubsets(left, leftsubsetsum);
    generatesubsets(right, rightsubsetsum);

    sort(rightsubsetsum.begin(), rightsubsetsum.end());

    int tot = 0;

    for (auto x : leftsubsetsum) {
        tot += upper_bound(rightsubsetsum.begin(), rightsubsetsum.end(), m - x) -
               lower_bound(rightsubsetsum.begin(), rightsubsetsum.end(), m - x);
        // if (binary_search(rightsubsetsum.begin(), rightsubsetsum.end(), m - x)) {
        // cout << x << " " << m - x << '\n';
        // cout << "Yes";
        // return 0;
        // }
    }
    // cout << "No";
    cout << tot;
    return 0;

}