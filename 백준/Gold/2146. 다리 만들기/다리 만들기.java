import java.util.*;

public class Main {
    static int[][] arr = new int[102][102];
    static int[][] island = new int[102][102];
    static int[][] visited = new int[102][102];
    static int[][] check = new int[102][102];
    static int n;
    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int temp = 2;
    static Queue<int[]> q= new LinkedList<>();
    static int ret = 100000;
    public static void dfs(int y, int x){
        arr[y][x] = temp;
        visited[y][x] = 1;

        for (int i=0; i<4; i++){
            int ny = y +dy[i];
            int nx = x +dx[i];

            if (ny <0 || nx < 0 || ny >= n || nx >=n) continue;
            if (arr[ny][nx] == 0) {
                int[] arrtemp = new int[]{ny,nx};
                q.add(arrtemp);
                visited[ny][nx] = 1;
                continue;
            }
            if(visited[ny][nx] != 0) continue;
            dfs(ny,nx);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n= sc.nextInt();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                arr[i][j] = sc.nextInt();
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if(arr[i][j] == 1 && visited[i][j] == 0) {
                    for (int[] rs : visited){
                        Arrays.fill(rs,0);
                    }
                    dfs(i,j);
                    while(!q.isEmpty()){
                        int y = q.peek()[0];
                        int x = q.peek()[1];

                        q.remove();

                        for (int k=0; k<4; k++){
                            int ny = y + dy[k];
                            int nx = x + dx[k];

                            if(ny < 0 || nx < 0 || ny >=n || nx >= n)continue;
                            if(arr[ny][nx] == 0 && visited[ny][nx] == 0) {
                                visited[ny][nx] = visited[y][x]+1;
                                q.add(new int[]{ny,nx});
                            }
                            else if (arr[ny][nx] != 0 && arr[ny][nx] != temp) ret = Math.min(ret,visited[y][x]);
                        }
                    }

                    temp++;
                }
            }
        }

        System.out.println(ret);
    }
}