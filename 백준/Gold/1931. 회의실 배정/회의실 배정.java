import java.util.*;

public class Main {
    static int n,cnt;
    static List<int[]> numList = new ArrayList<int[]>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i=0; i<n; i++){
            int s =0, e=0;
            s = sc.nextInt();
            e = sc.nextInt();
            int[] temp = {s,e};
            numList.add(temp);
        }
        Collections.sort(numList, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] == o2[1]) return o1[0]-o2[0];
                return o1[1] - o2[1];
            }
        });
        int j=0;
        for (int i=0;i<numList.size(); i++){
            if(i == 0){
                j = numList.get(i)[1];
                cnt++;
                continue;
            }
            if (numList.get(i)[0] < j)continue;
            j = numList.get(i)[1];
            cnt++;
        }
        System.out.println(cnt);
    }
}