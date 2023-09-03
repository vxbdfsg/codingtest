#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int> > dist(n, vector<int>(m, -1));
    dist[0][0]= 1;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while(!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return dist[n - 1][m - 1];
}

/*
아래 코드는 큐를 안쓴 코드(효율성테스트에서 탈락)
int an = -1;
void rfind(vector<vector<int>> temp, vector<vector<int>> maps, int i, int j, int answer);

int solution(vector<vector<int>> maps)
{
    vector<vector<int>> temp(maps.size(), vector<int>(maps[0].size(), 0));
    temp[0][0] = 1;
    rfind(temp, maps, 0, 0, 1);
    return an;
}

void rfind(vector<vector<int>> temp, vector<vector<int>> maps, int i, int j, int answer){
    //cout << i << " " << j << " " << answer << endl;
    if(i==maps.size()-1 && j == maps[0].size()-1){
        if(answer < an || an == -1){
            an = answer;
            //cout << "an : " << an << endl;
        }
    }
    if(i>0){
        if(maps[i-1][j] == 1 && temp[i-1][j] != 1){
            temp[i-1][j] = 1;
            rfind(temp, maps, i-1, j, answer+1);
            temp[i-1][j] = 0;
        }
    }
    if(i<maps.size()-1){
        if(maps[i+1][j] == 1&& temp[i+1][j] != 1){
            temp[i+1][j] = 1;
            rfind(temp, maps, i+1, j, answer+1);
            temp[i+1][j] = 0;
        }
    }
    if(j>0){
        if(maps[i][j-1] == 1&& temp[i][j-1] != 1){
            temp[i][j-1] = 1;
            rfind(temp, maps, i, j-1, answer+1);
            temp[i][j-1] = 0;
        }
    }
    if(j<maps[0].size()-1){
        if(maps[i][j+1] == 1&& temp[i][j+1] != 1){
            temp[i][j+1] = 1;
            rfind(temp, maps, i, j+1, answer+1);
            temp[i][j+1] = 0;
        }
    }
}*/
