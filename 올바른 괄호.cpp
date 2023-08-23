#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int total = 0;
    for(int i = 0 ; i < s.size() ; i ++){
        if(s[i] == '('){
            total +=1;
        }
        else if(s[i] == ')'){
            total -=1;
        }
        if(total<0){
            answer = false;
            i += s.size();
        }
    }
    if(total!=0){
        answer = false;
    }
    return answer;
}
