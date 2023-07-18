#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int> > land)
{
    int answer = 0;
    int bef = -1;
    for (int i = 0; i < land.size() - 1; i++) {
        bef = max_element(land[i].begin(), land[i].end()) - land[i].begin();;
        for (int j = 0; j < 4; j++) {
            if (j != bef) {
                land[i + 1][j] += land[i][bef];
            }
        }
        land[i][bef] = 0;
        int max = *max_element(land[i].begin(), land[i].end());;
        land[i + 1][bef] += max;
    }
    answer += *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());;
    return answer;
}