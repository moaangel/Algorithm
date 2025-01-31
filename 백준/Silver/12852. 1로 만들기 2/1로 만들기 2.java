import java.util.Arrays;
import java.util.Scanner;

public class Main{
    static int n;
    static int[] visited = new int[1000002];

    public static void go(int num){
        if(num < 1) return;
        System.out.print(num + " ");
        if (num % 3 == 0 && visited[num / 3] + 1 == visited[num]) go(num / 3);
        else if (num % 2 == 0 && visited[num / 2] + 1 == visited[num]) go(num / 2);
        else if (visited[num - 1]+1 == visited[num])go(num - 1);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        Arrays.fill(visited,10000000);
        visited[1] = 0;
        int temp = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0)visited[i] = Math.min(visited[i / 3] + 1, visited[i]);
            if (i % 2 == 0)visited[i] = Math.min(visited[i / 2] + 1, visited[i]);
            visited[i] = Math.min(visited[i - 1]+1, visited[i]);
        }
        System.out.println(visited[n]);
        go(n);
    }
}