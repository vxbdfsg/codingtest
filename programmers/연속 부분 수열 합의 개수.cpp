#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> elem) {
    vector<int> sum;
    for(int i = 0 ; i < elem.size() ; i++){
        int tmp = 0;
        for(int j = 0 ; j < elem.size() ; j++){
            tmp += elem[(i+j)%elem.size()];
            sum.push_back(tmp);
        }
    }
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    int answer = sum.size();
    return answer;
}
