import java.util.*;

public class Main{
    static int n;
    static long[] fibo = new long[50];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        fibo[0] = 0;
        fibo[1] = 1;
        for (int i=2; i<=45; i++){
            fibo[i] = fibo[i-1] + fibo[i-2];
        }
        System.out.println(fibo[n]);
    }
}