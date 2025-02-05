    import java.util.*;
    import java.io.*;

    public class Main {
        static int l, n, cnt;
        static int[] visited = new int[102];
        static ArrayList<Integer>[] arr = new ArrayList[102];

        static void go(int idx){
            for (int num : arr[idx]){
                if(visited[num] != 0) continue;
                visited[num] =1;
                cnt++;
                go(num);
            }
        }

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            l = sc.nextInt();
            n = sc.nextInt();
            for(int i=1; i<=l; i++){
                arr[i] = new ArrayList<Integer>();
            }
            for (int i=0; i<n; i++){
                int s = 0, e = 0;
                s = sc.nextInt();
                e = sc.nextInt();
                arr[s].add(e);
                arr[e].add(s);
            }
            visited[1] = 1;
            go(1);
            System.out.println(cnt);
        }
    }