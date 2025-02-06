import java.util.*;

public class Main {
    static int n, ret;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        List<Integer> arr = new ArrayList<>();
        for (int i=0; i<n; i++){
            int num =0;
            num = sc.nextInt();
            arr.add(num);
        }
        Collections.sort(arr);
        for (int i=0; i<n; i++){
            ret += arr.get(i) * (n-i);
        }
        System.out.println(ret);
    }
}