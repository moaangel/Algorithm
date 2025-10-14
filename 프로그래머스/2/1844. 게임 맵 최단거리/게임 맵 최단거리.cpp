#include<vector>
#include<queue>

using namespace std;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int visited[102][102];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || maps[ny][nx] == 0 || visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    if(visited[n-1][m-1])answer = visited[n-1][m-1];
    else answer = -1;
    return answer;
}