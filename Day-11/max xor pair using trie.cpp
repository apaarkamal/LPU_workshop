#include<bits/stdc++.h>
using namespace std;

struct node {
	node *nxt[2];
	int num;
	node() {
		nxt[0] = nxt[1] = NULL;
		num = 0;
	}
};

node *root;

void insert(int num) {
	node *cur = root;
	for (int bits = 20; bits >= 0; bits--) {
		int set = ((num >> bits) & 1);
		if (cur->nxt[set] == NULL) cur->nxt[set] = new node();
		cur = cur->nxt[set];
	}
	cur->num = num;
}

int give_best_choice(int num) {
	node *cur = root;
	for (int bits = 20; bits >= 0; bits--) {
		int set = ((num >> bits) & 1);
		if (cur->nxt[set ^ 1] == NULL) {
			cur = cur->nxt[set];
		}
		else {
			cur = cur->nxt[set ^ 1];
		}
	}
	return cur->num;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	root = new node();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		insert(a[i]);
	}

	// int m = 6;
	// max xor
	// int number = give_best_choice(m);
	// cout << number << " ";
	// cout << (m ^ number);
	int res = 0;

	for (int i = 0; i < n; i++) {
		res = max(res, (a[i] ^ give_best_choice(a[i])));
	}

	cout << res;
}