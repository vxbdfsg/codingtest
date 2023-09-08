#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> toppingCnt;
map<int, int> brother;

int solution(vector<int> topping) {
    int answer = 0;
    for(int i = 0 ; i < topping.size() ; i ++){
        toppingCnt[topping[i]] += 1;
    }
    for(int i = 0 ; i < topping.size() ; i ++){
        brother[topping[i]] += 1;
        toppingCnt[topping[i]] -= 1;
        if(toppingCnt[topping[i]] == 0){
            toppingCnt.erase(topping[i]);
        }
        if(brother.size() == toppingCnt.size()){
            answer+=1;
        }
    }
    return answer;
}
