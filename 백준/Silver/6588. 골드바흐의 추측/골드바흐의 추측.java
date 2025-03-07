import java.util.*;

public class Main{
    static int n;
    static boolean[] isPrime = new boolean[1000002];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        for (int i=2; i<=500000; i++){
            if(isPrime[i])continue;
            for (int j= i*2; j<1000000; j+=i){
                isPrime[j] = true;
            }
        }

        while(true){
            n = sc.nextInt();
            if(n == 0)return;
            int l = 3, r = n-1;
            boolean flag = false;
            while(l <= r){
                if(flag)break;
                if(isPrime[l]){
                    l += 2;
                    continue;
                }
                if(isPrime[r]){
                    r -= 2;
                    continue;
                }
                if(l + r < n) l+=2;
                else if (l + r == n)flag = true;
                else r -= 2;
            }
            if(flag){
                System.out.println(n + " = " + l + " + " + r);
            }
            else System.out.println("Goldbach's conjecture is wrong.");
        }

    }
}