#include<bits/stdc++.h>
using namespace std;

struct minheap {
	vector<int> v;

	minheap(vector<int> a) {
		v = a;
	}

	// O(logn)
	void heapify(int cur) {
		// left subtree and right subtree already heap
		int left = 2 * cur + 1, right = 2 * cur + 2;
		int min_idx = cur;

		if (left < v.size() && v[left] < v[min_idx]) {
			min_idx = left;
		}
		if (right < v.size() && v[right] < v[min_idx]) {
			min_idx = right;
		}
		if (min_idx != cur) {
			swap(v[min_idx], v[cur]);
			heapify(min_idx);
			return ;
		}
		return ;
	}

	// ??
	void build_heap() {
		int last_child = v.size() - 1;
		int last_parent = (last_child - 1) / 2;
		for (int i = last_parent; i >= 0; i--) {
			heapify(i);
		}
	}

	// O(1)
	int top() {
		return v[0];
	}

	bool isempty() {
		return v.empty();
	}

	int size() {
		return v.size();
	}

	// O(logn)
	void pop() {
		swap(v[0], v.back());
		v.pop_back();
		heapify(0);
	}

	// O(logn)
	void push(int val) {
		v.push_back(val);
		int idx = v.size() - 1;
		int par = (idx - 1) / 2;

		while (idx > 0 && v[par] > v[idx]) {
			swap(v[idx], v[par]);
			idx = par;
			par = (idx - 1) / 2;
		}

		return;
	}

};

// O(nlogn)
void heap_sort(vector<int> &a) {
	minheap H(a);
	H.build_heap();

	for (int i = 0; i < a.size(); i++) {
		// O(1)
		a[i] = H.top();
		// O(logn)
		H.pop();
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// minheap H(a);
	// H.build_heap();
	// H.pop();
	// cout << H.top() << '\n';
	// H.push(3);

	heap_sort(a);
	for (auto x : a) cout << x << " ";

}