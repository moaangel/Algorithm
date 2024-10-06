import java.util.*;
class Solution {
    public int[] solution(int[] numbers) {
        HashSet<Integer> hs = new HashSet<>();
        for (int i=0; i<numbers.length; i++){
            for (int j = i+1; j<numbers.length; j++){
                int temp = numbers[i] + numbers[j];
                hs.add(temp);
            }
        }
        int arrsize = hs.size();
        int[] answer = new int[arrsize];
        int i=0;
        for (int a : hs) {
            answer[i] = a;
            i++;
        }
        Arrays.sort(answer);
        return answer;
    }
}