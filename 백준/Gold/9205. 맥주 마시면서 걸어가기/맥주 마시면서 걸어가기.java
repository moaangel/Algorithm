import java.util.*;

public class Main {
    static int t,n;
    static boolean flag;
    static int[] visited = new int[105];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        for (int tc =0; tc<t; tc++){
            n = sc.nextInt();
            Arrays.fill(visited,0);
            flag = false;
            List<int[]> lists = new ArrayList<>();
            for (int i = 0; i < n + 2; i++){
                int s = sc.nextInt(), e = sc.nextInt();
                lists.add(new int[]{s,e});
            }
            Queue<int[]> queue = new LinkedList<>();
            visited[0] = 1;
            queue.add(new int[]{lists.get(0)[0],lists.get(0)[1]});
            while(!queue.isEmpty()){
                if(visited[n+1] == 1) break;
                int[] yx = queue.poll();

                for (int i=0; i<n+2; i++){
                    if(visited[i] == 1)continue;
                    if(Math.abs(yx[0]-lists.get(i)[0]) + Math.abs(yx[1]-lists.get(i)[1]) > 1000)continue;
                    visited[i] = 1;
                    if(i == n+1) flag = true;
                    queue.add(new int[]{lists.get(i)[0],lists.get(i)[1]});
                }
            }
            if(flag) System.out.println("happy");
            else System.out.println("sad");
        }
    }
}