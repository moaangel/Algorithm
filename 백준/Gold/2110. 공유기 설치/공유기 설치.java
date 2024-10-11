import java.util.*;

public class Main {
    static int c,ans;
    static List<Integer> arr = new ArrayList<>();
    public static boolean check(int mid){
        int count = 1;
        int prev = arr.get(0);
        for (int i=0;i<arr.size(); i++){
            if (arr.get(i) - prev < mid) continue;
            count++;
            prev = arr.get(i);
            if (count == c)break;
        }
        if (count >= c)return true;
        else return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        c = sc.nextInt();

        int l=0,r=0;
        for (int i=0; i<n; i++){
            int num = sc.nextInt();
            arr.add(num);
            if(r < num) r = num;
        }
        Collections.sort(arr);
        while(l<=r){
            int mid = (l+r) / 2;
            if (check(mid)){
                ans = mid;
                l= mid+1;
            }
            else r = mid-1;
        }

        System.out.println(ans);
    }
}