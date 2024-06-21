import java.util.Queue;
import java.util.LinkedList;
import java.awt.Point;


class Solution {
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};

    static int[][] visited = new int[102][102];
    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length;
        int m = maps[0].length;
        Queue<Point> q = new LinkedList<>();
        visited[0][0] = 1;
        q.add(new Point(0,0));
        while(!q.isEmpty()){
            Point p = q.poll();           
            int y = p.x;
            int x = p.y;            
            
            for (int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
                if (maps[ny][nx] == 1 && visited[ny][nx] == 0){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.add(new Point(ny,nx));
                }
            }
        }
        if (visited[n-1][m-1] != 0)answer = visited[n-1][m-1];
        else answer = -1;
        return answer;
    }
}