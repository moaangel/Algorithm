import java.util.*;

public class Main{
    static int r,c, startY,startX;
    static char[][] arr;
    static int[][] visited;
    static int[][] fireVisited;
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        arr = new char[r][c];
        visited = new int[r][c];
        fireVisited = new int[r][c];
        Queue<int[]> fireQ = new LinkedList<>();
        for (int i=0; i<r; i++){
            Arrays.fill(fireVisited[i],Integer.MAX_VALUE);
        }

        for (int i=0; i<r; i++){
            String temp = sc.next();
            for (int j=0; j<c; j++){
                arr[i][j] = temp.charAt(j);
                if (arr[i][j] == 'J'){
                    startY = i;
                    startX = j;
                    visited[i][j] = 1;
                }
                if (arr[i][j] == 'F') {
                    fireQ.add(new int[]{i,j});
                    fireVisited[i][j]= 1;
                }
            }
        }
        while(!fireQ.isEmpty()){
            int[] yx = fireQ.poll();
            int y = yx[0];
            int x = yx[1];

            for (int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >=  r || nx >= c) continue;
                if (arr[ny][nx] == '#' || fireVisited[ny][nx] <= fireVisited[y][x] + 1) continue;
                fireVisited[ny][nx] = fireVisited[y][x] + 1;
                fireQ.add(new int[]{ny,nx});
            }

        }
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{startY,startX});
        while(!q.isEmpty()){
            int[] yx = q.poll();
            int y = yx[0];
            int x = yx[1];

            for (int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >=  r || nx >= c) continue;
                if(arr[ny][nx] == '#' || fireVisited[ny][nx] <= visited[y][x] + 1 || visited[ny][nx] != 0)continue;
                visited[ny][nx] = visited[y][x] + 1 ;
                q.add(new int[]{ny,nx});
            }
        }
        int answer = Integer.MAX_VALUE;
        for(int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if(i == 0 || j == 0 || i == r-1 || j == c-1){
                    if(visited[i][j] != 0)answer = Math.min(answer,visited[i][j]);
                }
            }
        }
        if(answer == Integer.MAX_VALUE) System.out.println("IMPOSSIBLE");
        else System.out.println(answer);
    }
}