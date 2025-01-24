import java.util.*;

public class Main {
    static int n,x,ret =0;

    public static void main(String[] args) {
        List<Integer> numList = new ArrayList<Integer>();

            Scanner sc = new Scanner(System.in);
            n = sc.nextInt();
            for (int i=0; i<n; i++){
                int num = 0;
                num = sc.nextInt();
                numList.add(num);
            }
            x = sc.nextInt();
        Collections.sort(numList);
        int s = 0, e = numList.size() - 1;
        while(s < e){
            if(numList.get(s) + numList.get(e) < x){
                s++;
            }
            else if (numList.get(s) + numList.get(e) == x){
                s++;
                ret++;
            }
            else{
                e--;
            }
        }
        System.out.println(ret);
    }
}