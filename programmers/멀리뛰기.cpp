#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    if(n == 1){
        answer = 1;
    }
    else if(n == 2){
        answer = 2;
    }
    else{
        int a1 = 1;
        int a2 = 2;
        int t = 0;
        for(int i = 2 ; i < n ; i++){
            t = a1 + a2;
            t %= 1234567;
            a1 = a2;
            a2 = t;
        }
        answer = t;
    }
    return answer%1234567;
}
