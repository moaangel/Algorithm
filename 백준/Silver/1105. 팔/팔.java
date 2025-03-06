import java.util.*;

public class Main{
    static String l,r;
    static int answer;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        l = sc.next();
        r = sc.next();
        if(l.equals(r)){
            for (int i=0; i<l.length(); i++){
                if(l.charAt(i) == '8')answer++;
            }
            System.out.println(answer);
        } else if (l.length() != r.length()) {
            System.out.println(0);
        } else {
            for (int i=0; i<l.length(); i++){
                if (l.charAt(i) == '8' && r.charAt(i) == '8')answer++;
                else if (l.charAt(i) == r.charAt(i)) continue;
                else break;
            }
            System.out.println(answer);
        }
    }
}