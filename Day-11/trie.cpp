#include<bits/stdc++.h>
using namespace std;


struct node {
	node *nxt[26];
	bool is_end;
	node() {
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
		is_end = false;
	}
};

node *root;

void insert(string name) {
	node *cur = root;
	for (int i = 0; i < name.size(); i++) {
		int index = name[i] - 'a';
		if (cur->nxt[index] == NULL) cur->nxt[index] = new node();
		cur = cur->nxt[index];
	}
	cur->is_end = true;
	return;
}

bool search(string name) {
	node *cur = root;
	for (int i = 0; i < name.size(); i++) {
		int index = name[i] - 'a';
		if (cur->nxt[index] == NULL) return false;
		cur = cur->nxt[index];
	}
	return cur->is_end;
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
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		insert(name);
	}

	if (search("vishal")) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

}