import java.util.*;
import java.io.*;

public class Main {
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    static int n,m,k;
    static void dfs(int y, int x, int[][] arr, boolean[][] visited){
        visited[y][x] = true;

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx] || arr[ny][nx] == 0)continue;
            dfs(ny,nx,arr,visited);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc=0; tc<t; tc++){
            int ans=0;
            m = sc.nextInt(); n = sc.nextInt(); k = sc.nextInt();
            int[][] arr = new int[n][m];
            boolean[][] visited = new boolean[n][m];
            for (int i=0; i<k; i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                arr[y][x] = 1;
            }
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    if (arr[i][j] == 1 && !visited[i][j]){
                        ans++;
                        dfs(i,j,arr,visited);
                    }
                }
            }
            System.out.println(ans);
        }
    }
}