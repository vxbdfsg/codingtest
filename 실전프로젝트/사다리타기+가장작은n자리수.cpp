#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector <int> v;
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			v.push_back((int)temp[j] - 48);
		}
		sort(v.begin(), v.end());
		string num = "";
		int count = 0;
		for (int k = 0; k < v.size(); k++) {
			if (v[k] == 0) {
				count += 1;
			}
			else {
				if (num == "") {
					num += to_string(v[k]);
					for (int h = 0; h < count; h++) {
						num += "0";
					}
				}
				else {
					num += to_string(v[k]);
				}
			}
		}
		cout << num << endl;
	}





	
	
	int d, t, n, m;
	cin >> d;
	//d t n m 을 순서를 잘못 넣어서 t n m d순이 되어야 하는게 맞음
	for (int j = 0; j < d; j++) {
		cin >> t;
		cin >> n;
		cin >> m;
		vector <string> v;
		for (int k = 0; k <= n; k++) {
			string temp;
			getline(cin, temp);
			v.push_back(temp);
		}
		for (int i = v.size() - 1; i >= 3; i--) {
			if (m * 2 - 1 <= 2 * t - 1 && m * 2 - 3 >= 0) {
				if (v[i - 1][m * 2 - 1] == '+') {
					m += 1;
				}
				else if (v[i - 1][m * 2 - 3] == '+') {
					m -= 1;
				}
			}
		}
		cout << m << endl;
	}
	return 0;
}
