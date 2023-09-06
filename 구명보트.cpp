#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int i = 0;
    int j = people.size()-1;
    while(i<=j){
        if(limit >= people[i]+people[j]){
            i++;
            j--;
        }
        else{
            j--;
        }
        answer +=1;
    }
    return answer;
}
