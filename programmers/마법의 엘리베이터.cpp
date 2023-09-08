#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey != 0){
        if(storey%10 > 5){
            answer += (10-storey%10);
            storey/=10;
            storey+=1;
        }
        else if(storey%10 == 5){
            int tmp = (storey/10) % 10;                                                           
            if(tmp >= 5) {
                storey = storey / 10;
                storey = storey + 1;
            }
            else {
                storey = storey / 10;
            }
            answer = answer + 5;
        }
        else{
            answer += storey%10;
            storey/=10;
        }
    }
    return answer;
}
