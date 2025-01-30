import java.util.*;

public class Main {
    static int n,m,l=1, r,ret;
    static int[] arr = new int[100002];

    static boolean check(int mid){
        int temp = 0;
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (temp >= arr[i]){
                temp -= arr[i];
            }
            else{
                temp = mid;
                cnt++;
                if(temp< arr[i])return false;
                temp -= arr[i];
            }
        }
        return cnt <= m;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
            r += arr[i];
        }

        while(l<=r){
            int mid = (l+r) / 2;
            if (check(mid)){
                ret = mid;
                r = mid - 1;
            } else{
                l = mid +1;
            }
        }
        System.out.println(ret);
    }
}