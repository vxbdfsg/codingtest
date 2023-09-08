#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    while(pq.size() > 1 && pq.top() < K){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min1 + min2*2);
        answer += 1;
    }
    if(pq.top() < K){
        answer = -1;
    }
    return answer;
}
