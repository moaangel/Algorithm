import java.util.*;

public class Main{
    static int n,k,l, dir,answer;
    static Deque<int[]> deque = new ArrayDeque<>();
    static boolean[][] visited;
    static boolean[][] apple;
    static Map<Integer,Character> mp = new HashMap<>();
    static int[] dy = {0,1,0,-1};
    static int[] dx = {1,0,-1,0};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        visited = new boolean[n][n];
        apple = new boolean[n][n];

        for (int i=0; i<k; i++){
            int y = sc.nextInt();
            int x = sc.nextInt();
            apple[y-1][x-1] = true;
        }

        l = sc.nextInt();

        for (int i=0; i<l; i++){
            int time = sc.nextInt();
            char dir = sc.next().charAt(0);
            mp.put(time,dir);
        }
        deque.add(new int[]{0,0});
        visited[0][0] = true;
        while(!deque.isEmpty()){
            int y = deque.peekFirst()[0];
            int x = deque.peekFirst()[1];
            answer++;
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]){
                break;
            }
            deque.addFirst(new int[]{ny,nx});
            visited[ny][nx] = true;
            if (!apple[ny][nx]) {
                visited[deque.peekLast()[0]][deque.peekLast()[1]] = false;
                deque.removeLast();
            }
            apple[ny][nx] = false;

            if(!mp.isEmpty() && mp.containsKey(answer)){
                if (mp.get(answer) == 'D')dir = (dir + 1) % 4;
                else {
                    dir -= 1;
                    if (dir == -1)dir = 3;
                }
            }
        }

        System.out.println(answer);
    }
}