#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a!=b){
        int t = a/2;
        t += a%2;
        a = t;
        t = b/2;
        t += b%2;
        b = t;
        answer += 1;
    }
    return answer;
}
