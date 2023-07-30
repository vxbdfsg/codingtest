#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> inpark;
    vector<int> time1;
    vector<int> time2;
    for(int i = 0 ; i < records.size() ; i ++){
        if(records[i].substr(11,2) == "IN"){
            if(find(inpark.begin(), inpark.end(), records[i].substr(6,4)) == inpark.end()){
                inpark.push_back(records[i].substr(6,4));
                int t = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2));
                time1.push_back(t);
                time2.push_back(0);
            }
            else{
                int idx = find(inpark.begin(), inpark.end(), records[i].substr(6,4)) - inpark.begin();
                int t = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2));
                time1[idx] = t;
            }
        }
        else{
            int idx = find(inpark.begin(), inpark.end(), records[i].substr(6,4)) - inpark.begin();
            int t = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2));
            time2[idx] += t - time1[idx];
            time1[idx] = -1;
        }
    }
    for(int i = 0 ; i < time1.size() ; i ++){
        if(time1[i] != -1){
            time2[i] += 1439-time1[i];
        }
    }
    for(int i = 0 ; i < time2.size() ; i ++){
        int f = 0;
        if(time2[i] < fees[0]){
            f += fees[1];
        }
        else{
            f += fees[1];
            time2[i] -= fees[0];
            while(time2[i]>0){
                f += fees[3];
                time2[i] -= fees[2];
            }
        }
        time2[i] = f;
    }
    vector<string> time3;
    time3.resize(inpark.size());
    answer.resize(inpark.size());
    copy(inpark.begin(), inpark.end(), time3.begin());
    sort(time3.begin(), time3.end());
    for(int i = 0 ; i < time1.size() ; i++){
        int idx = find(inpark.begin(), inpark.end(), time3[i]) - inpark.begin();
        cout << time2[i] << " ";
        answer[i] = time2[idx];
    }
    return answer;
}
