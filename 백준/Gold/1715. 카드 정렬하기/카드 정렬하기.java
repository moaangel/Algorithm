import java.util.*;

public class Main{
    static int n;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] cardList = new int[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i=0; i<n; i++){
            cardList[i] = sc.nextInt();
            pq.add(cardList[i]);
        }
        int answer =0;
        while(pq.size() != 1){
            int x = pq.poll();
            int y = pq.poll();
            answer += (x+y);
            pq.add(x+y);
        }
        System.out.println(answer);

    }
}