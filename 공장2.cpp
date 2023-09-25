#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;
		vector <string> v;
		for (int k = 0; k <= n; k++) {
			string temp;
			getline(cin, temp);
			v.push_back(temp);
		}
		v.erase(v.begin());
		vector <__int64_t> A;
		vector <__int64_t> B;
		__int64_t sumA = 0;
		__int64_t sumB = 0;
		for (int i = 0; i < v.size(); i++) {

			if (v[i][0] == 'O') {
				if (v[i][v[i].size() - 1] == 'A') {
					A.push_back(v[i][v[i].size() - 3]-'0');
					sumA += v[i][v[i].size() - 3] - '0';
				}
				else if (v[i][v[i].size() - 1] == 'B') {
					B.push_back(v[i][v[i].size() - 3]-'0');
					sumB += v[i][v[i].size() - 3] - '0';
				}
				else if (v[i][v[i].size() - 1] == 'C') {
					if (sumA <= sumB) {
						A.push_back(v[i][v[i].size() - 3] - '0');
						sumA += v[i][v[i].size() - 3] - '0';
					}
					else {
						B.push_back(v[i][v[i].size() - 3] - '0');
						sumB += v[i][v[i].size() - 3] - '0';
					}
				}
			}
			else if (v[i][0] == 'D') {
				if (v[i][v[i].size() - 1] == 'A') {
					sumA -= A[0];
					A.erase(A.begin());
				}
				else if (v[i][v[i].size() - 1] == 'B') {
					sumB -= B[0];
					B.erase(B.begin());
				}
			}
		}
		cout << sumA << " " << sumB << endl;
	}
	return 0;
}
