#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int sum = 0;
    for(int i = 1 ; i < n ; i ++){
        for(int j = i ; j < n ; j ++){
            sum+=j;
            if(sum == n){
                answer +=1;
                j = n+1;
            }
            else if(sum > n){
                sum = 0;
                j = n+1;
            }
        }
    }
    return answer;
}
