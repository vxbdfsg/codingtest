#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int one = 0;
    int num = 0;
    /*for(int i = 0 ; i < s.size() ; i ++){
        if(s[i] == '1'){
            one +=1;
        }
    }*/
    while (s != "1"){
        for(int i = s.size()-1 ; i >=0  ; i --){
            if(s[i] == '0'){
                one +=1;
                s.erase(s.begin()+i);
            }
        }
        int len = s.size();
        string temp = "";
        while(len != 0)
            {
            if (len % 2 == 1) // 나머지가 1
                temp += '1';
            else			// 나머지가 0
                temp += '0';
            len /= 2; 		// X가 0이 될 때까지 2로 계속해서 나눈다.
        }
        s = temp;
        num+=1;
    }
    answer.push_back(num);
    answer.push_back(one);
    return answer;
}
