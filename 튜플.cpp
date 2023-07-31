#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/*https://school.programmers.co.kr/learn/courses/30/lessons/64065*/

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> sl;
    string t = "";
    for(int i = 0 ; i < s.size() ; i++){
        if(isdigit(s[i])){
            t += s[i];
        }
        else{
            if(t!= ""){
                sl.push_back(stoi(t));
                t = "";
            }
        }
    }
    vector<int> temp_sl;
    temp_sl.resize(sl.size());
    copy(sl.begin(), sl.end(), temp_sl.begin());
    sort(temp_sl.begin(), temp_sl.end());
    temp_sl.erase(unique(temp_sl.begin(), temp_sl.end()), temp_sl.end());
    answer.resize(temp_sl.size());
    for(int i = 0 ; i < temp_sl.size() ; i ++){
        int cnt = 0;
        cnt = count(sl.begin(), sl.end(), temp_sl[i]);
        answer[cnt-1] = temp_sl[i];
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
