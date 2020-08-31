#include<bits/stdc++.h>
using namespace std;

class minstack() {
public:
	vector<pair<int, int>> v;

	void push(int x) {
		if (v.empty()) v.push_back({x, x});
		else v.push_back({x, min(x, v.back().second)});
	}

	void pop() {
		v.pop_back();
	}

	int top() {
		return v.back().first;
	}

	int getMin() {
		return v.back().second;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code


}