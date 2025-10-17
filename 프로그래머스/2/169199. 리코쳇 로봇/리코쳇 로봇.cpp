#include <string>
#include <vector>
#include <queue>

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};


int sY,sX,eY,eX;

struct Node{
    int y, x, cnt;
};

using namespace std;

int solution(vector<string> board) {
    for(int i=0; i<board.size(); i++){
        for (int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'G'){ eY = i, eX = j; }
            if(board[i][j] == 'R'){ sY = i, sX = j; }
        }
    }
    int visited[102][102];
    for(int i=0; i<102; i++)
        for(int j=0; j<102; j++)
            visited[i][j] = -1;
    
    queue<Node> q;
    q.push({sY,sX,0});
    visited[sY][sX] = 0;
    
    while(q.size()){
        Node currentNode = q.front();
        q.pop();
        
        if(currentNode.y == eY && currentNode.x == eX)return currentNode.cnt;
        
        for (int i=0; i<4; i++){
            int ny = currentNode.y;
            int nx = currentNode.x;
            
            while(1){
                int ty = ny + dy[i];
                int tx = nx + dx[i];
                
                 if (ty < 0 || tx < 0 || ty >= board.size() || tx >= board[0].size() || board[ty][tx] == 'D')break;
                ny = ty;
                nx = tx;
            }
            if(visited[ny][nx] == -1 || visited[ny][nx] > currentNode.cnt+1){
                visited[ny][nx] = currentNode.cnt+1;
                q.push({ny,nx,currentNode.cnt+1});
            }
        }
    }
    return -1;
}