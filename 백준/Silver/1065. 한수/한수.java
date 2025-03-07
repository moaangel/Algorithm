import java.util.*;

public class Main{
    static int n;

    static boolean check(String number){
        int temp =number.charAt(1) - number.charAt(0);
        for (int i=1; i<number.length()-1; i++){
            if(number.charAt(i+1) - number.charAt(i) != temp)return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        if (n < 100) System.out.println(n);
        else{
            int cnt =99;
            for (int i=100; i<=n; i++){
                if(check(Integer.toString(i)))cnt++;
            }
            System.out.println(cnt);
        }
    }
}