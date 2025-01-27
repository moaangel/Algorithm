import java.util.Scanner;

public class Main {
    static int ret = 100003;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int[] psum = new int[n+2];
        for (int i=0; i<n; i++){
            int num = sc.nextInt();
            if (i == 0) {
                psum[i] = num;
                continue;
            }
            psum[i] = psum[i-1] + num;
        }
        if(psum[n-1] < s){
            System.out.println(0);
            return;
        }
        else{
            for (int i=0; i<n; i++){
                if(psum[i] < s)continue;
                ret = Math.min(ret,i+1);
                int j = (Math.max(i - ret, 0));
                for (; j<i; j++){
                    int temp = psum[i] - psum[j];
                    if(temp >= s){
                        ret = Math.min(ret,i - j);
                        continue;
                    }
                    else break;
                }
            }
        }
        System.out.println(ret);
    }
}