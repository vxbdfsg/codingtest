#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string change(int i, int n){
    string temp = "";
    while(1){
        if(i%n < 10){
            temp += to_string(i%n);
        }
        else if (i%n == 10) { temp += "A"; }
        else if (i%n == 11) { temp += "B"; }
        else if (i%n == 12) { temp += "C"; }
        else if (i%n == 13) { temp += "D"; }
        else if (i%n == 14) { temp += "E"; }
        else if (i%n == 15){ temp += "F"; }
        i = i/n;
        if(i == 0){
            break;
        }
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    for(int i = 0 ; i < t*m ; i ++){
        temp += change(i, n);
        if(temp.size()>t*m){
            i += t*m;
        }
    }
    for(int i = 0 ; i < t ; i ++){
        answer += temp[i*m+p-1];
    }
    return answer;
}
