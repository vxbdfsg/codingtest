#include <string>
#include <vector>

using namespace std;

int maxk = -1;
int greedy(int k, vector<vector<int>> d, int m);
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    greedy(k, dungeons, 0);
    answer = maxk;
    return answer;
}

int greedy(int k, vector<vector<int>> d, int m) {
    for (int i = 0; i < d.size(); i++) {
        int p = k;
        int mp = m;
        vector<vector<int>> temp_d(d.size());
        if (p >= d[i][0]) {
            p -= d[i][1];
            mp += 1;
        }
        else {
            continue;
        }
        if (mp >= maxk) {
            maxk = mp;
        }
        for (int j = 0; j < d.size(); j++) {
            temp_d[j] = d[j];
        }
        temp_d.erase(temp_d.begin() + i);
        greedy(p, temp_d, mp);
    }
    return 0;
}