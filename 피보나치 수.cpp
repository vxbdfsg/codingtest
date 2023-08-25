#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int b = 1;
    for(int i = 0; i < n ; i++){
        int c = b;
        b = answer+b;
        answer = c;
        b%=1234567;
        answer%=1234567;
    }
    return answer;
}
