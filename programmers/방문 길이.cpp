#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector < vector <float> > v;
    float x = 0.0;
    float y = 0.0;
    for(int i = 0 ; i < dirs.size() ; i ++){
        if(dirs[i] == 'U'&&y<=4.0){
            y += 0.5;
            v.push_back({x, y});
            y += 0.5;
        }
        else if(dirs[i] == 'D'&&y>=-4.0){
            y -= 0.5;
            v.push_back({x, y});
            y -= 0.5;
        }
        else if(dirs[i] == 'R'&&x<=4.0){
            x += 0.5;
            v.push_back({x, y});
            x += 0.5;
        }
        else if(dirs[i] == 'L'&&x>=-4.0){
            x -= 0.5;
            v.push_back({x, y});
            x -= 0.5;
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
}
