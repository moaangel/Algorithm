import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int[][] dp = new int[1002][3];
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        dp[0][0] = sc.nextInt();
        dp[0][1] = sc.nextInt();
        dp[0][2] = sc.nextInt();

        for (int i=1; i<num; i++){
            int r = sc.nextInt();
            int g = sc.nextInt();
            int b = sc.nextInt();

            dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) +r;
            dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) +g;
            dp[i][2] = Math.min(dp[i-1][1], dp[i-1][0]) +b;
        }

        int ret = Math.min(dp[num-1][0],Math.min(dp[num-1][1],dp[num-1][2]));

        System.out.println(ret);
    }
}