#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> temp(board.size() + 2, vector<int>(board.size() + 2, 0));
    for(int i = 0 ; i < board.size() ; i ++){
        for(int j = 0 ; j < board.size() ; j ++){
            if(board[i][j] == 1){
                temp[i+2][j+2] = 1;
                temp[i+2][j+1] = 1;
                temp[i+2][j] = 1;
                temp[i+1][j+2] = 1;
                temp[i+1][j+1] = 1;
                temp[i+1][j] = 1;
                temp[i][j+2] = 1;
                temp[i][j+1] = 1;
                temp[i][j] = 1;
            }
        }
    }
    for(int i = 1 ; i <= board.size() ; i ++){
        for(int j = 1 ; j <= board.size() ; j ++){
            if(temp[i][j] == 0){
                answer +=1;
            }
        }
    }
    return answer;
}
