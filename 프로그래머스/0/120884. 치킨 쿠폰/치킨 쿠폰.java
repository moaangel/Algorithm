class Solution {
    public int solution(int chicken) {
        int answer = 0;
        int tc =0;
        while(true){
            tc += chicken % 10;
            chicken /= 10;
            answer += chicken;
            if (tc >= 10){
                tc -= 10;
                tc += 1;
                answer += 1;
            }
            if (chicken==0)break; 
        }
        if (tc>= 10) answer++;
        return answer;
    }
}