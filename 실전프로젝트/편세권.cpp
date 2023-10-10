#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;
		vector < vector <int> > con;
		vector < vector <int> > map(n+22, vector <int>(n+22, 0));
		int c;
		cin >> c;
		for (int i = 0; i < c; i++)
		{
			int row;
			int col;
			cin >> row >> col;
			con.push_back({ row + 11, col + 11 });
		}
		for (int j = 0; j < con.size(); j++)
		{
			for (int i = 0; i < map.size() * map.size(); i++)
			{
				int row = i / map.size();
				int col = i % map.size();
				if (con[j][0] == row && con[j][1] == col) {
					map[row][col] -= 1000;
				}
				if (abs(con[j][0] - row) + abs(con[j][1] - col) <= 10) {
					if (abs(con[j][0] - row) + abs(con[j][1] - col) <= 3) {
						map[row][col] += 3;
					}
					else
					{
						map[row][col] += 1;
					}
				}
			}
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i+11][j+11] << " ";
			}
			cout << endl;
		}*/

		int score = 0;
		int tr = 0;
		int tc = 0;
		for (int i = 0; i < n*n; i++)
		{
			int row = i / n;
			int col = i % n;
			row += 11;
			col += 11;
			if (score < map[row][col]) {
				score = map[row][col];
				tr = row;
				tc = col;
			}
		}
		cout << tr - 11 << " " << tc - 11 << " " << score << endl;
	}
	return 0;
}
