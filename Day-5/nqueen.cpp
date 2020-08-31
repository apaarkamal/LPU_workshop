#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int grid[N][N];
int n;

void print_grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (grid[i][j] ? "Q " : ". ");
		} cout << '\n';
	}
	cout << '\n';
	exit(0);
}

bool safe(int row, int col) {

	int rrow = row, ccol = col;

	// same column
	while (rrow >= 0) {
		if (grid[rrow][ccol]) return false;
		rrow--;
	}

	// left diagonal
	rrow = row; ccol = col;
	while (rrow >= 0 && ccol >= 0) {
		if (grid[rrow][ccol]) return false;
		rrow--; ccol--;
	}

	// right diagonal
	rrow = row; ccol = col;
	while (rrow >= 0 && ccol < n) {
		if (grid[rrow][ccol]) return false;
		rrow--; ccol++;
	}

	return true;
}

void nqueen(int row) {
	if (row == n) {
		print_grid();
		return;
	}

	for (int col = 0; col < n; col++) {
		// try to place a queen at that column
		if (safe(row, col)) {
			// place the queen
			grid[row][col] = 1;
			nqueen(row + 1);
			// backtracking
			// remove the queen
			grid[row][col] = 0;
		}
	}
	return;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	cin >> n;
	nqueen(0);
}