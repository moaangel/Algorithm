import java.util.*;
import java.io.*;
public class Main{
    static int n, d, k, c,ret, temp;
    static List<Integer> fishList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        d =  sc.nextInt();
        k = sc.nextInt();
        c = sc.nextInt();
        int[] visited = new int[d+1];
        for (int i=0; i<n; i++){
            int num = 0;
            num = sc.nextInt();
            fishList.add(num);
        }
        int num = 0;
        for (int i=0; i<k; i++){
            visited[fishList.get(i)]++;
            if (visited[fishList.get(i)] == 1)num++;
        }
        if (visited[c] == 0)num++;
        ret = num;
        if(n == k){
            System.out.println(ret);
            return;
        }
        int nextNum = num;
        if(visited[c] == 0)nextNum--;
        int i = 0, j = k;
        while(j < n){
            visited[fishList.get(i)]--;
            if(visited[fishList.get(i)] == 0)nextNum--;
            i++;
            visited[fishList.get(j)]++;
            if(visited[fishList.get(j)] == 1){
                nextNum++;
            }
            j++;

            if(visited[c] == 0)ret = Math.max(ret, nextNum +1);
            else ret = Math.max(ret,nextNum);

        };
        j = 0;
        while(i < n){
            visited[fishList.get(i)]--;
            if(visited[fishList.get(i)] == 0)nextNum--;
            i++;
            visited[fishList.get(j)]++;
            if(visited[fishList.get(j)] == 1){
                nextNum++;
            }
            j++;

            if(visited[c] == 0)ret = Math.max(ret, nextNum +1);
            else ret = Math.max(ret,nextNum);

        }

        System.out.println(ret);
    }
}