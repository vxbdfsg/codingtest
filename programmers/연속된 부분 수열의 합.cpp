#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int len = sequence.size();
    int sum = 0;
    int j = 0;
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] > k) {
            break;
        }
        sum += sequence[i];
        while (sum > k) {
            sum -= sequence[j];
            j += 1;
        }
        if (sum == k && i - j < len) {
            len = i - j;
            answer[0] = j;
            answer[1] = i;
        }
    }
    return answer;
}
