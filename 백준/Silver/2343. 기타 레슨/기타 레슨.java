import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int min = 0;
        int max = 0;

        for (int i = 0; i < N; i++) {
            min = Math.max(min, arr[i]);
            max += arr[i];
        }

        while (min < max) {
            int mid = (min + max) / 2;
            int count = 1;
            int sum = 0;

            for (int i = 0; i < N; i++) {
                if (sum + arr[i] > mid) {
                    count++;
                    sum = arr[i];
                } else {
                    sum += arr[i];
                }
            }

            if (count <= M) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }

        System.out.println(min);
    }
}
