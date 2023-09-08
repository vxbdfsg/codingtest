#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    s += " ";
    string temp = "";
    vector<int> t;
    for(int i = 0 ; i < s.size() ; i ++){
        if(s.substr(i,1) != " "){
            temp += s[i];
        }
        else if(s.substr(i,1) == " "){
            t.push_back(stoi(temp));
            temp = "";
        }
    }
    int max = t[0];
    int min = t[0];
    for(int i = 0 ; i < t.size() ; i ++){
        if(t[i] > max){
            max = t[i];
        }
        if(t[i] < min){
            min = t[i];
        }
    }
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    return answer;
}
