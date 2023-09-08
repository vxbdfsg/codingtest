#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    /*
    처음에 했다가 효율성에서 통과못한 코드
    int answer = 0;
    int temp = 1;
    while(temp != 0){
        temp = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                temp = 1;
                i -= 2;
            }
        }
    }
    if(s.size() == 0){
        answer = 1;
    }
    return answer;
    */
    stack<char> st;
    int answer = 0;
    for(int i=0; i<s.size(); i++){
        if(st.size() > 0 && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    answer = !st.size();
    
    return answer;
}
