import java.util.*;

public class Main{
    static int n, answer = 2000000002,x,y;
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n];
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int l = 0, r = n-1;
        while(l<r){
            if(arr[l] + arr[r] == 0){
                x = arr[l];
                y = arr[r];
                break;
            } else if(arr[l] + arr[r] > 0){
                if(answer > Math.abs(arr[l] + arr[r])){
                    x = arr[l];
                    y = arr[r];
                    answer = Math.abs(arr[l] + arr[r]);
                }
                r--;
            }
            else {
                if(answer > Math.abs(arr[l] + arr[r])){
                    x = arr[l];
                    y = arr[r];
                    answer = Math.abs(arr[l] + arr[r]);
                }
                l++;
            }
        }
        System.out.println(x + " " + y);
    }
}