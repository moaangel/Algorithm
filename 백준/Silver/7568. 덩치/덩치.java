import java.util.*;

public class Main{
    static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        List<int[]> arr = new ArrayList<>();
        for (int i=0; i<n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr.add(new int[]{x,y});
        }
        for (int i=0; i<n; i++){
            int rank = 1;
            for (int j=0; j<n; j++){
                if (i==j) continue;
                if(arr.get(i)[0] >= arr.get(j)[0] && arr.get(i)[1] >= arr.get(j)[1])continue;
                else if((arr.get(i)[0] > arr.get(j)[0] && arr.get(i)[1] < arr.get(j)[1]) || (arr.get(i)[0] < arr.get(j)[0] && arr.get(i)[1] > arr.get(j)[1]))continue;
                else if ((arr.get(i)[0] < arr.get(j)[0] && arr.get(i)[1] < arr.get(j)[1]))rank++;
            }
            System.out.print(rank + " ");
        }
    }
}