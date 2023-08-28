#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int tn = n;
    while (tn!=0){
        sum += tn%2;
        tn/=2;
    }
    cout << sum;
    int temp = 0;
    while(temp != sum){
        temp = 0;
        n+=1;
        tn = n;
        while (tn!=0){
            temp += tn%2;
            tn/=2;
        }
    }
    answer = n;
    return answer;
}
