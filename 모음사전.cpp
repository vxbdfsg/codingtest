#include <string>
#include <vector>

using namespace std;
vector<int> num = {781, 156, 31, 6, 1};
int solution(string word) {
    int answer = 0;
    answer += word.size();
    for(int i = 0 ; i < word.size() ; i ++){
        if(word[i] == 'E'){
            answer += num[i];
        }
        if(word[i] == 'I'){
            answer += num[i]*2;
        }
        if(word[i] == 'O'){
            answer += num[i]*3;
        }
        if(word[i] == 'U'){
            answer += num[i]*4;
        }
    }
    return answer;
}
