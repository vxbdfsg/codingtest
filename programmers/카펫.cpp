#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tbrown = brown + 4;
    tbrown/=2;
    for(int i = tbrown ; i >= tbrown/2 ; i --){
        int j = tbrown - i;
        int ty = (i - 2)*(j - 2);
        if(ty == yellow && answer.size() == 0){
            answer.push_back(i);
            answer.push_back(j);
        }
    }
    return answer;
}
