#include<bits/stdc++.h>
using namespace std;

int n;

const int N = 100;
int grid[N][N];

int dx[8] = { -1, -1, -2, -2, 1, 1, 2, 2};
int dy[8] = { -2, 2, -1, 1, -2, 2, -1, 1};

void print_grid() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << "\t";
		}
		cout << '\n';
	}
	cout << '\n';

}

void knight_move(int row, int col, int move) {
	grid[row][col] = move;
	if (move == n * n) {
		print_grid();
		grid[row][col] = 0;
		return;
	}
	// simply go to other cells
	for (int i = 0; i < 8; i++) {
		int next_row = row + dx[i];
		int next_col = col + dy[i];

		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n && grid[next_row][next_col] == 0) {
			knight_move(next_row, next_col, move + 1);
		}

	}
	// backtrack
	grid[row][col] = 0;
	return;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	cin >> n;

	knight_move(0, 0, 1);

}