#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    if(isalpha(s[0])){
        s[0] = toupper(s[0]);
    }
    for(int i = 0 ; i < s.size() ; i ++){
        if(isalpha(s[i+1]) && s.substr(i,1) == " "){
            s[i+1] = toupper(s[i+1]);
        }
        else if(isalpha(s[i+1])){
            s[i+1] = tolower(s[i+1]);
        }
    }
    answer = s;
    return answer;
}
