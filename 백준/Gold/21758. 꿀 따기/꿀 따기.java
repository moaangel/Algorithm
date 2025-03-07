import java.util.*;

public class Main{
    static int n;
    static int[] pSum, reversePSum;
    static int[] arr;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n];
        pSum = new int[n];
        reversePSum = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
            if(i == 0)pSum[i] = arr[i];
            else{
                pSum[i] = pSum[i-1] + arr[i];
            }
        }
        for (int i =n-1; i>=0; i--){
            if (i== n-1) reversePSum[i] = arr[n-1];
            else {
                reversePSum[i] = reversePSum[i+1] + arr[i];
            }
        }
        int answer =0;
        for (int i=0; i<n; i++){
            if (i == 0){
                for (int j= 1; j<n-1; j++){
                    int temp = reversePSum[0]- reversePSum[n-1];
                    temp -= arr[j];
                    temp += reversePSum[0];
                    temp -= reversePSum[j];
                    answer = Math.max(answer,temp);
                }
                continue;
            }
            if (i == n-1){
                for (int j=n-2; j>= 1; j--){
                    int temp = pSum[n-1] - pSum[0];
                    temp -=arr[j];
                    temp += pSum[n-1];
                    temp -= pSum[j];
                    answer = Math.max(answer,temp);
                }
                continue;
            }
            int temp = (pSum[i] - pSum[0]) + (reversePSum[i] - reversePSum[n-1]);
            answer = Math.max(answer,temp);
        }
        System.out.println(answer);
    }
}