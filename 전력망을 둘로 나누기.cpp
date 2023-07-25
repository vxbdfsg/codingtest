#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for (int j = 0; j < wires.size(); j++) {
        vector<vector<int>> temp_wires(wires.size());
        temp_wires.assign(wires.size(), vector<int>(wires.size()));
        copy(wires.begin(), wires.end(), temp_wires.begin());
        vector<int> temp;
        temp.push_back(temp_wires[j][0]);
        temp.push_back(temp_wires[j][1]);
        vector<int> left;
        vector<int> right;
        left.push_back(temp_wires[j][0]);
        right.push_back(temp_wires[j][1]);
        temp_wires.erase(temp_wires.begin() + j);
        while (temp_wires.size() > 0) {
            for (int i = 0; i < temp_wires.size(); i++) {
                if (find(left.begin(), left.end(), temp_wires[i][0]) != left.end() || find(left.begin(), left.end(), temp_wires[i][1]) != left.end()) {
                    left.push_back(temp_wires[i][0]);
                    left.push_back(temp_wires[i][1]);
                    temp_wires.erase(temp_wires.begin() + i);
                }
                if (find(right.begin(), right.end(), temp_wires[i][0]) != right.end() || find(right.begin(), right.end(), temp_wires[i][1]) != right.end()) {
                    right.push_back(temp_wires[i][0]);
                    right.push_back(temp_wires[i][1]);
                    temp_wires.erase(temp_wires.begin() + i);
                }
            }
        }
        if (find(left.begin(), left.end(), temp[0]) == left.end()) {
            right.push_back(temp[0]);
        }
        if (find(left.begin(), left.end(), temp[1]) == left.end()) {
            right.push_back(temp[1]);
        }
        sort(left.begin(), left.end());
        left.erase(unique(left.begin(), left.end()), left.end());
        sort(right.begin(), right.end());
        right.erase(unique(right.begin(), right.end()), right.end());
        cout << "-----" << endl;
        cout << temp[0] << " " << temp[1] << endl;
        for (int i = 0; i < left.size(); i++) {
            cout << left[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < right.size(); i++) {
            cout << right[i] << " ";
        }
        cout << endl;
        int a = left.size() - right.size();
        if (answer > abs(a)) {
            answer = abs(a);
        }
    }

    return answer;
}