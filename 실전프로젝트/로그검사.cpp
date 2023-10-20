#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		cin >> n;
		int num_error = 0;
		vector <string> vlog;
		for( int i = 0; i <= n; i ++)
		{
			string log;
			
			getline(cin, log);
		
			vlog.push_back(log);
		}
		vlog.erase(vlog.begin());
		for (int i = 0; i < n; i++)
		{
			vector<string> words;
			stringstream ss(vlog[i]);
			string word;
			while (getline(ss, word, ' ')) {
				words.push_back(word);
			}

			/*for (int j = 0; j < words.size(); j++)
			{
				cout << words[j] << " ";
			}
			cout << endl;*/

			if (vlog[i].size() > 100) {
				num_error += 1;
			}
			else if (words.size() != 12)
			{
				num_error += 1;
			}
			else if (words[0] != "line_name" || words[3] != "product_name"
				|| words[6] != "error_level" || words[9] != "message") {
				num_error += 1;
			}
			else if (words[1] != ":" || words[4] != ":"
				|| words[7] != ":" || words[10] != ":") {
				num_error += 1;
			}
			else if(words.size() == 12)
			{
				bool chk = false;
				for (int k = 0; k < words[2].size(); k++)
				{
					if (!isalpha(words[2][k])) {
						chk = true;
					}
				}
				for (int k = 0; k < words[5].size(); k++)
				{
					if (!isalpha(words[5][k])) {
						chk = true;
					}
				}
				for (int k = 0; k < words[8].size(); k++)
				{
					if (!isalpha(words[8][k])) {
						chk = true;
					}
				}
				for (int k = 0; k < words[11].size(); k++)
				{
					if (!isalpha(words[11][k])) {
						chk = true;
					}
				}
				if (chk) {
					num_error += 1;
				}
			}
		}
		cout << num_error << endl;
	}
	return 0;
}
