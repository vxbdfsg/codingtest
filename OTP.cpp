#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;
		vector <double> v;
		for (int i = 0; i < n*3; i++){
			double c;
			cin >> c;
			v.push_back(c);
		}
		cin >> m;

		for (int i = 0; i < m; i++){
			unsigned int u, t, x;
			cin >> u >> t >> x;
			bool chk = false;
			for (int k = t-3; k <= t+3 ; k++){
				__int64_t utp = 0;
				utp += v[u * 3 - 3] * ((k * k)%999983);
				utp += v[u * 3 - 2] * (k % 999983);
				utp += v[u * 3 - 1];
				if (utp % 999983 == x) {
					chk = true;
				}
			}
			if (chk) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
