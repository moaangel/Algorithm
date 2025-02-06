import java.util.Scanner;

public class Main {
    static int n, ret;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        for (int i=0; i<n; i++){
            int temp =0;
            for (int j = i+1; j<n; j++){
                if(arr[i] > arr[j])temp++;
                else break;
            }
            ret = Math.max(temp,ret);
        }
        System.out.println(ret);
    }
}