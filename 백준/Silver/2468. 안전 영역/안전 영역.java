import java.util.*;

public class Main {
    static int[][] arr = new int[102][102];
    static boolean[][] visited = new boolean[102][102];
    static int ret = 0,n;
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    static void dfs(int y, int x, int depth){
        visited[y][x] = true;

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(arr[ny][nx] <= depth || visited[ny][nx]) continue;
            dfs(ny,nx,depth);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int mx = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                arr[i][j] = sc.nextInt();
                mx = Math.max(mx,arr[i][j]);
            }
        }

        for (int k=0;k<=mx; k++){
            for(boolean[] temp : visited){
                Arrays.fill(temp, false);
            }
            int cnt =0;
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if(arr[i][j] >k && !visited[i][j]){
                       cnt++;
                       dfs(i,j,k);
                    }
                }
            }
            ret = Math.max(ret,cnt);
        }

        System.out.println(ret);
    }
}