import java.util.*;

public class Main {
    static int n, ret=2000;
    static int[][] arr = new int[22][22];

    static int check(List<Integer> start, List<Integer> link){
        int ateam=0 , bteam =0;
        for (int i=0; i<n/2; i++){
            for (int j=0; j<n/2; j++){
                if (i == j) continue;
                ateam += arr[start.get(i)][start.get(j)];
                bteam += arr[link.get(i)][link.get(j)];
            }
        }
        return Math.abs(ateam-bteam);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int temp = sc.nextInt();
                arr[i][j] = temp;
            }
        }
        for (int i=0; i < (1<<n); i++){
            List<Integer>start = new ArrayList<>();
            List<Integer>link = new ArrayList<>();
            for (int j=0; j<n; j++){
                if ((i & (1 << j)) != 0)start.add(j);
                else link.add(j);
            }
            if(start.size() == n/2){
                ret = Math.min(ret, check(start,link));
            }
        }
        System.out.println(ret);
    }
}