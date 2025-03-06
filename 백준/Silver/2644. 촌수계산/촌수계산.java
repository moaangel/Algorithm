import java.util.*;

public class Main {
    static int n, targetX, targetY, m, answer=102;
    static List<List<Integer>> arr = new ArrayList<>();
    static int[] visited = new int[102];
    static void dfs(int index, int cnt){
        visited[index] = 1;
        if (index == targetY){
            if (answer > cnt)
                answer = cnt;
            return;
        }
        for(int num : arr.get(index)){
            if (visited[num] == 1) continue;
            dfs(num,cnt+1);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i=0; i<n; i++){
            arr.add(new ArrayList<>());
        }
        arr.add(new ArrayList<>());
        targetX = sc.nextInt();
        targetY = sc.nextInt();
        m = sc.nextInt();
        for(int i=0; i<m; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr.get(x).add(y);
            arr.get(y).add(x);
        }
        dfs(targetX,0);
        if(answer == 102) System.out.println(-1);
        else System.out.println(answer);
        return;
    }
}