import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        int answer = 0;
        int[] dy = {1,0,-1,0};
        int[] dx = {0,1,0,-1};
        int n = maps.length;
        int m = maps[0].length;
        int[][] visited = new int[n][m];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0});
        visited[0][0]= 1;
        while(!q.isEmpty()){
            int[] yx = q.poll();
            int y = yx[0];
            int x = yx[1];
            
            for (int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] != 0 || maps[ny][nx] == 0)continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.add(new int[]{ny,nx});
            }
        }
        answer = visited[n-1][m-1];
        if(answer == 0) answer = -1;
        
        return answer;
    }
}