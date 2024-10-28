import java.util.Scanner;

public class Main {
    static int n,m,j,ret;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        j = sc.nextInt();
        int start = 1;
        int end = m;
        for (int i=0; i<j; i++){
            int temp = sc.nextInt();
            if(start <= temp && end >= temp){
                continue;
            }
            else if (temp > end){
                int cnt = 0;
                if(end + (temp - end) > n){
                    cnt = n - end;

                }
                else {
                    cnt = temp - end;
                }
                    end += cnt;
                    start += cnt;
                    ret += cnt;
            }
            else if(temp < start) {
                int cnt = 0;
                if(start - (start - temp) < 1){
                    cnt = start -1;
                }
                else {
                    cnt = start - temp;
                }
                    end -= cnt;
                    start -= cnt;
                    ret += cnt;
            }

        }
        System.out.println(ret);
    }
}