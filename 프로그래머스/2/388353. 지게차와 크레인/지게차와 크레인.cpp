#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n = storage.size(), m = storage[0].length();
    for (int i = 0; i < requests.size(); i++){
        char target = requests[i][0];
        if(requests[i].length() == 2){
            for(int j=0; j<n; j++){
                for (int k=0; k<m; k++){
                    if(storage[j][k] == target) storage[j][k] = '.'; 
                }
            }
        }
        else{
            vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
            visited[0][0] = true;
            queue<pair<int,int>> q;
            q.push({0,0});
            while (!q.empty()) {
                auto [y, x] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0 || nx < 0 || ny > n + 1 || nx > m + 1) continue;
                    if (visited[ny][nx]) continue;
                    visited[ny][nx] = true;

                    // 실제 창고 내부면
                    if (1 <= ny && ny <= n && 1 <= nx && nx <= m) {
                        char &cell = storage[ny - 1][nx - 1];
                        if (cell == '.') {
                            q.push({ny, nx});
                        } else if (cell == target) {
                            cell = '.'; // 접근 가능한 target 제거
                        }
                    } else {
                        // 바깥쪽은 자유롭게 이동
                        q.push({ny, nx});
                    }
                }
            }
        }
    }


    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            if (storage[y][x] != '.')
                answer++;
        }
    }
    return answer;
}