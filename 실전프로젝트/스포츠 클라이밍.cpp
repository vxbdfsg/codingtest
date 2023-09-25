#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector < vector <int> > v(501, vector <int>(501, 0));
vector < vector <int> > v2(501, vector <int>(501, 0));

bool is_in_box(int n, int y, int x)
{
	if (0 > x || x >= n)
		return false;
	if (0 > y || y >= n)
		return false;
	return true;
}

bool r2(int y, int x1, int x2) {
	for (int i = x1; i <= x2; i++){
		if (v[y-1][i] != 0) {
			return false;
		}
		if (i != x1 && i != x2) {
			if (v[y][i] != 0) {
				return false;
			}
		}
	}
	return true;
}

bool r4(int y, int x) {
	if (v[y][x - 1] != 0 || v[y - 1][x] != 0) {
		return false;
	}
	return true;
}

bool r5(int y, int x) {
	if (v[y][x + 1] != 0 || v[y - 1][x] != 0) {
		return false;
	}
	return true;
}

int solve(int n, int y, int x, int step) {
	if (v2[y][x] != -1 && v2[y][x] <= step)
		return 0;
	int next = step + 1;
	v2[y][x] = next;

	//rule 1
	if (is_in_box(n, y - 1, x) && v[y - 1][x] == 1)
		solve(n, y - 1, x, next);
	if (is_in_box(n, y + 1, x) && v[y + 1][x] == 1)
		solve(n, y + 1, x, next);
	if (is_in_box(n, y, x + 1) && v[y][x + 1] == 1)
		solve(n, y, x + 1, next);
	if (is_in_box(n, y, x - 1) && v[y][x - 1] == 1)
		solve(n, y, x - 1, next);

	//rule 2
	if (is_in_box(n, y, x + 2) && v[y][x + 2] == 1 && y != 0 && r2(y, x, x + 2))
		solve(n, y, x + 2, next);
	if (is_in_box(n, y, x - 2) && v[y][x - 2] == 1 && y != 0 && r2(y, x - 2, x))
		solve(n, y, x - 2, next);
	if (is_in_box(n, y, x + 3) && v[y][x + 3] == 1 && y != 0 && r2(y, x, x + 3))
		solve(n, y, x + 3, next);
	if (is_in_box(n, y, x - 3) && v[y][x - 3] == 1 && y != 0 && r2(y, x - 3, x))
		solve(n, y, x - 3, next);

	// rule 3
	if (is_in_box(n, y - 2, x) && v[y - 1][x] == 0 && v[y - 2][x] == 1)
		solve(n, y - 2, x, next);

	// rule 4
	if (is_in_box(n, y - 1, x - 1) && v[y - 1][x - 1] == 1 && r4(y, x))
		solve(n, y - 1, x - 1, next);
	// rule 5
	if (is_in_box(n, y - 1, x + 1) && v[y - 1][x + 1] == 1 && r5(y, x))
		solve(n, y - 1, x + 1, next);
}

int main() {
	int d, t, n, m;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;
		for (int i = 0; i < n*n; i++){
			v[i / n][i % n] = 0;
			v2[i / n][i % n] = 0;
			char input;
			cin >> input;
			if (input == 'H') {
				v[i / n][i % n] = 1;
				v2[i / n][i % n] = -1;
			}
			else if (input == 'X') {
				v[i / n][i % n] = -1;
			}
			else {
				v[i / n][i % n] = 0;
			}
		}
		solve(n, n - 1, 0, 0);
		for (int i = 0; i < n; i++){
			for (int k = 0; k < n; k++){
				cout << v2[i][k] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
