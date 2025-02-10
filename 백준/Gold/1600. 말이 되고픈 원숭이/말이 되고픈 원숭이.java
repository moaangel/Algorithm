import java.util.*;

public class Main {
    static int k,m,n;
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    static int[] doubledx = {2, 1, -1, -2, -2, -1, 1, 2};
    static int[] doubledy = {1, 2, 2, 1, -1, -2, -2, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        m = sc.nextInt();
        n = sc.nextInt();
        int[][] arr = new int[n+2][m+2];
        boolean[][][] visited = new boolean[n+2][m+2][k+1];

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                arr[i][j] = sc.nextInt();
            }
        }


        Queue<int[]> q = new LinkedList<>();
        visited[0][0][0] = true;
        q.add(new int[]{0,0,0,0});
        while (!q.isEmpty()){
            int[] yxkv = q.poll();
            int y = yxkv[0];
            int x = yxkv[1];
            int kNum = yxkv[2];
            int visit = yxkv[3];

            if(y == n-1 && x == m-1){
                System.out.println(visit);
                return;
            }
            if(kNum < k){
                for (int i=0; i<8; i++){
                    int ny = y + doubledy[i];
                    int nx = x + doubledx[i];

                    if(ny < 0 || nx < 0 || ny>=n || nx >=m || arr[ny][nx] == 1 || visited[ny][nx][kNum + 1]) continue;
                    visited[ny][nx][kNum+1] = true;
                    q.add(new int[]{ny,nx,kNum +1, visit + 1});
                }
            }

            for (int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny>=n || nx >=m || arr[ny][nx] == 1 || visited[ny][nx][kNum])continue;
                visited[ny][nx][kNum] = true;
                q.add(new int[]{ny,nx,kNum,visit+1});
            }
        }
        System.out.println(-1);
        return;
    }
}