import java.util.Arrays;
class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        for (int i = citations[citations.length-1]; i>=0; i--){
            int num = i;
            int cnt = 0;
            for (int j = citations.length-1; j>=0; j--){
                if(citations[j] >= num)cnt++;
                else break;
            }
            if(cnt >= num && num >= (citations.length - cnt)){
                answer = num;
                break;
            }
        }
        return answer;
    }
}