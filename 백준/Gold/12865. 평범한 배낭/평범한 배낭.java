import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{
    static int n,k;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        List<int[]> lists = new ArrayList<>();
        int[][] dp = new int[n+1][k+1];
        for (int i = 0; i<n; i++){
            int s = sc.nextInt(), e = sc.nextInt();
            lists.add(new int[]{s,e});
        }
        for (int i=1; i<=n;i++){
            for (int j=1; j<= k; j++){
                if (j >= lists.get(i-1)[0])
                    dp[i][j] = Math.max(dp[i-1][j],dp[i-1][j-lists.get(i-1)[0]] + lists.get(i-1)[1]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        System.out.println(dp[n][k]);
    }
}