import java.util.*;

public class Main{
    static int n, targetNumber, answerCount;
    static int[] numberArray;

    static void check(int index, int num){
        if(index == n) {
            if(num == targetNumber)answerCount++;
            return;
        }

        check(index+1,num + numberArray[index]);
        check(index+1,num);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        targetNumber = sc.nextInt();
        numberArray = new int[n];
        for (int i=0; i<n; i++){
            numberArray[i] = sc.nextInt();
        }

        check(0,0);
        if (targetNumber == 0)answerCount--;
        System.out.println(answerCount);
    }
}