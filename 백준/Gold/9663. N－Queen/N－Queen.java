import java.util.Scanner;
import java.lang.*;

import static java.lang.Math.abs;

public class Main{
    static int n,ret;

    static int[] arr = new int[15];

    static boolean check(int row,int col){
        for (int i=0; i<col; i++){
            if(arr[i] == row)return false;
            if ((col-i) == abs(row-arr[i]))return false;
        }
        return true;
    }

    static void nqueen(int col){
        if (col == n){
            ret++;
            return;
        }

        for (int i=0; i<n;i++) {
            if (check(i,col)){
                arr[col] = i;
                nqueen(col+1);
            }
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        nqueen(0);
        System.out.println(ret);
    }
}