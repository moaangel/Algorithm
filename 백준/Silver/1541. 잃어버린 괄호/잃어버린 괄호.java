import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String temp = "";
        int first=0;
        int sec =0;
        boolean flag = false;
        for (int i=0; i<s.length(); i++){
            if (s.charAt(i)=='+'){
                if(flag) {
                    sec += Integer.parseInt(temp);
                    temp = "";
                }
                else {
                    first += Integer.parseInt(temp);
                    temp = "";
                }
            }
            else if (s.charAt(i) == '-'){
                if(flag) {
                    sec += Integer.parseInt(temp);
                    temp = "";
                }
                else {
                    first += Integer.parseInt(temp);
                    temp = "";
                }
                flag = true;
            }
            else temp += s.charAt(i);
        }
        if(flag) {
            sec +=  Integer.parseInt(temp);
        }
        else{
            first += Integer.parseInt(temp);
        }
        System.out.println(first - sec);
    }
}