#include<bits/stdc++.h>
using namespace std;

const int N = 9;
int grid[N][N];

void print_grid() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	// exit(0);
}

bool safe(int row, int col, int digit) {
	// row check
	for (int i = 0; i < N; i++) {
		if (grid[row][i] == digit) return false;
	}

	// col check
	for (int i = 0; i < N; i++) {
		if (grid[i][col] == digit) return false;
	}

	// block check
	int startrow = (row / 3) * 3;
	int startcol = (col / 3) * 3;

	for (int i = startrow; i < startrow + 3; i++) {
		for (int j = startcol; j < startcol + 3; j++) {
			if (grid[i][j] == digit) return false;
		}
	}

	return true;

}

void sudoku_solver(int row, int col) {
	if (row == N) {
		print_grid();
		return;
	}

	if (grid[row][col] == 0) {
		// then fill the values
		// recur for the next cell
		for (int digits = 1; digits <= 9; digits++) {
			if (safe(row, col, digits)) {

				grid[row][col] = digits;

				if (col + 1 == N) sudoku_solver(row + 1, 0);
				else sudoku_solver(row, col + 1);

				// backtrack
				grid[row][col] = 0;

			}
		}
	}
	else {
		// dont fill the values
		// recur for the next cell
		if (col + 1 == N) {
			sudoku_solver(row + 1, 0);
		}
		else {
			sudoku_solver(row, col + 1);
		}
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	sudoku_solver(0, 0);
}