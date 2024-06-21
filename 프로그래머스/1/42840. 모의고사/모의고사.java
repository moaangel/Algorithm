import java.util.List;
import java.util.ArrayList;

class Solution {
    public ArrayList<Integer> solution(int[] answers) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[] one = {1,2,3,4,5};
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};
        int[] scores = new int[3];
        for (int i=0; i<answers.length; i++){
            if (answers[i] == one[i%5])scores[0]++;
            if (answers[i] == two[i%8])scores[1]++;
            if (answers[i] == three[i%10])scores[2]++;
        }
        int mx = Math.max(scores[0], Math.max(scores[1],scores[2]));
        int cnt=0;
        for (int i=0; i<3; i++){
            if (mx == scores[i])cnt++;
        }
        int j =0;
        for (int i=0; i<3; i++){
            if (mx == scores[i]){
                answer.add(i+1);
                j++;
            }
        }
        
        return answer;
    }
}