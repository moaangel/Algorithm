import java.util.*;
class Solution {
    public int[] solution(int[][] score) {
        int[] answer = new int[score.length];
        Double[] temp = new Double[score.length];
        for(int i=0; i<score.length; i++){
            temp[i] = (score[i][0] + score[i][1]) * 1.0 / 2;
        }
        List<Double> list = new ArrayList<>(Arrays.asList(temp));
        Collections.sort(list, Collections.reverseOrder());
        
        for (int i = 0; i < temp.length; i++) {
            answer[i] = list.indexOf(temp[i]) + 1;
        }
        return answer;
    }
}