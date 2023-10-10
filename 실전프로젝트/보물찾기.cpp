#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int r = 0;
		int c = 0;
		char bd = 'B';
		int n;
		cin >> n;
		vector < vector <char> > dir(n, vector <char>(n, 0));
		vector < vector <int> > dis(n, vector <int>(n, 0));
		vector < vector <char> > ans(n, vector <char>(n, 0));
		for (int i = 0; i < n * n; i++) {
			char s;
			cin >> s;
			dir[i / n][i % n] = s;
			int d;
			cin >> d;
			dis[i / n][i % n] = d;
		}
		while (ans[r][c] != bd)
		{
			//cout << r << " " << c << " " << bd << " " << ans[r][c] << endl;
			if (bd == 'B' && dir[r][c] == 'B') {
				bd = 'F';
			}
			else if (bd == 'B' && dir[r][c] == 'F') {
				bd = 'B';
			}
			else if (bd == 'B' && dir[r][c] == 'L') {
				bd = 'R';
			}
			else if (bd == 'B' && dir[r][c] == 'R') {
				bd = 'L';
			}// B
			else if (bd == 'L' && dir[r][c] == 'B') {
				bd = 'R';
			}
			else if (bd == 'L' && dir[r][c] == 'L') {
				bd = 'B';
			}
			else if (bd == 'L' && dir[r][c] == 'R') {
				bd = 'F';
			}
			else if (bd == 'L' && dir[r][c] == 'F') {
				bd = 'L';
			}//L
			else if (bd == 'R' && dir[r][c] == 'B') {
				bd = 'L';
			}
			else if (bd == 'R' && dir[r][c] == 'L') {
				bd = 'F';
			}
			else if (bd == 'R' && dir[r][c] == 'R') {
				bd = 'B';
			}
			else if (bd == 'R' && dir[r][c] == 'F') {
				bd = 'R';
			}//R
			else if (bd == 'F' && dir[r][c] == 'B') {
				bd = 'B';
			}
			else if (bd == 'F' && dir[r][c] == 'L') {
				bd = 'L';
			}
			else if (bd == 'F' && dir[r][c] == 'R') {
				bd = 'R';
			}
			else if (bd == 'F' && dir[r][c] == 'F') {
				bd = 'F';
			}
			if (ans[r][c] == bd) {
				break;
			}
			ans[r][c] = bd;
			if (bd == 'R') {
				c += dis[r][c];
			}
			else if (bd == 'L') {
				c -= dis[r][c];
			}
			else if (bd == 'B') {
				r -= dis[r][c];
			}
			else if (bd == 'F') {
				r += dis[r][c];
			}
		}
		cout << r << " " << c << endl;
	}
	return 0;
}
