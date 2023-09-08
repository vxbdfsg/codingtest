#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long Calculate(long long N1, long long N2, char Op)
{
    if (Op == '*') return N1 * N2;
    if (Op == '+') return N1 + N2;
    if (Op == '-') return N1 - N2;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> digit;
    vector<char> ex;
    vector<char> p = { '+','-','*','+','*','-','-','+','*','-','*','+','*','+','-','*','-','+' };
    int start = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            digit.push_back(stoi(expression.substr(start, i)));
            ex.push_back((expression.at(i)));
            start = i + 1;
        }
    }
    digit.push_back(stoi(expression.substr(start, expression.size() - 1)));
    for (int j = 0; j < 6; j++) {
        vector<long long> temp_digit = digit;
        vector<char> temp_ex = ex;
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < ex.size(); i++) {
                if (find(temp_ex.begin(), temp_ex.end(), p[j * 3 + k]) != temp_ex.end()) {
                    int idx = find(temp_ex.begin(), temp_ex.end(), p[j * 3 + k]) - temp_ex.begin();
                    cout << idx << " ";
                    temp_ex.erase(temp_ex.begin() + idx);
                    temp_digit[idx] = Calculate(temp_digit[idx], temp_digit[idx + 1], p[j * 3 + k]);
                    temp_digit.erase(temp_digit.begin() + idx + 1);
                }
                else {
                    break;
                }
            }
        }
        answer = max(answer, abs(temp_digit[0]));
    }
    return answer;
}