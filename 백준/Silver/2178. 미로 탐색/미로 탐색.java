import java.awt.*;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main{
    static int n,m;
    static int[][] arr = new int[102][102];
    static int[][] visited = new int[102][102];

    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i=0; i<n; i++){
            String temp = sc.next();
            for (int j=0; j<m; j++){
                arr[i][j] = temp.charAt(j) - '0';
            }
        }

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(0,0));
        visited[0][0] = 1;
        while(!q.isEmpty()){
            Point p = q.poll();
            int y = p.y;
            int x = p.x;

            for (int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
                if (arr[ny][nx] == 1 && (visited[ny][nx] > visited[y][x] + 1 || visited[ny][nx] == 0)){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.add(new Point(nx,ny));
                }
            }
        }
        System.out.println(visited[n-1][m-1]);
    }
}