#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int start, int target, int sum);
int answer = 0;
int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, target, 0);
    return answer;
}
void dfs(vector<int> numbers, int start, int target, int sum) {
    if (start == numbers.size() && sum == target) {
        answer += 1;
    }
    else if (start < numbers.size()) {
        int sum1 = sum;
        sum1 += numbers[start];
        int sum2 = sum;
        sum2 -= numbers[start];
        int start1 = start;
        start1 += 1;
        dfs(numbers, start1, target, sum1);
        dfs(numbers, start1, target, sum2);
    }
}