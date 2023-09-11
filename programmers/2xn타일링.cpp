#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int a = 0;
    int b = 1;
    for(int i = 1 ; i <= n ; i++){
        answer = (a + b)%1000000007;
        a = b%1000000007;;
        b = answer;
        
    }
    return answer;
}
