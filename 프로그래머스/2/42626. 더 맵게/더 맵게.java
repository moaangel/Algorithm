import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i : scoville){
            pq.add(i);
        }
        while(pq.size()>0){
            if(pq.peek() < K){
                if(pq.size()==1)return -1;
                answer++;
                int a = pq.poll();
                int b = pq.poll();
                b *= 2;
                int num = a + b;
                pq.add(num);
            }
            else return answer;
        }
        return answer;
    }
}