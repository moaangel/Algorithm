import java.util.Scanner;

public class Main {

    static void change(char[] arr, char[] org, int idx){
        arr[idx-1] = arr[idx-1] == '1' ? '0' : '1';
        arr[idx] = arr[idx] == '1' ? '0' : '1';
        if(idx != arr.length-1) arr[idx+1] = arr[idx+1] == '1' ? '0' : '1';
    }

    static int go(char[] arr, char[] org, int start){
        int cnt = start;

        if(start == 1){
            arr[0] = arr[0] == '1' ? '0' : '1';
            arr[1] = arr[1] == '1' ? '0' : '1';
        }

        for (int i=0; i<arr.length-1; i++){
            if (arr[i] == org[i])continue;
            else {
                cnt++;
                change(arr,org,i+1);
            }
        }
        boolean flag = false;
        for (int i=0; i<arr.length; i++){
            if(arr[i] != org[i]){
                flag = true;
                break;
            }
        }

        if(flag) cnt = -1;
        return cnt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String a = sc.next();
        String b = sc.next();
        char[] arr = a.toCharArray();
        char[] org = b.toCharArray();
        if (a.equals(b)) {
            System.out.println(0);
            return;
        }
        int ret1 = go(arr,org,0);
        arr = a.toCharArray();
        int ret2 = go(arr,org,1);
        if(ret1 == -1 && ret2 == -1)
            System.out.println(-1);
        else if (ret1 == -1)
            System.out.println(ret2);
        else if (ret2== -1)
            System.out.println(ret1);
        else System.out.println(Math.min(ret1,ret2));

    }
}
