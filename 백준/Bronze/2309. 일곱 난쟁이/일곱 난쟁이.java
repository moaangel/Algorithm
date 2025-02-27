import java.util.ArrayList;
import java.util.Arrays;
import java.util.*;
import java.util.Scanner;

public class Main{
    static int[] arr = new int[9];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum =0;
        for (int i=0; i<9; i++){
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        int[] flag = new int[2];
        for (int i=0; i<9; i++){
            for (int j= i+1; j<9; j++){
                if (sum - (arr[i] + arr[j]) == 100){
                    flag[0] = i; flag[1] = j;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i=0; i<9; i++){
            if (i == flag[0] || i == flag[1])continue;
            ans.add(arr[i]);
        }
        Collections.sort(ans);
        for (int num : ans){
            System.out.println(num);
        }
    }
}