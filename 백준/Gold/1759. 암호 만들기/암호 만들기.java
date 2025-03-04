import java.util.*;

public class Main{
    static int l,c;
    static String[] arr;

    static void check(int idx, String password){
        if (password.length() > l)return;
        if (idx == c){
            if(password.length() == l) {
                int tempNum = 0;
                for (int i = 0; i < password.length(); i++) {
                    if (password.charAt(i) == 'a' || password.charAt(i) == 'e' || password.charAt(i) == 'i' || password.charAt(i) == 'o' || password.charAt(i) == 'u')
                        tempNum++;
                }
                if (tempNum + 2 <= password.length() && tempNum > 0) {
                    System.out.println(password);
                }
            }
            return;
        }
        check(idx+1, password + arr[idx]);
        check(idx+1, password);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        l = sc.nextInt();
        c = sc.nextInt();
        arr = new String[c];
        for (int i=0; i<c; i++){
            arr[i] = sc.next();
        }
        Arrays.sort(arr);
        check(0, "");
    }
}