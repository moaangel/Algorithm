import java.util.ArrayList;
import java.util.Comparator;

class Solution {
    public ArrayList<Integer> solution(int[] array, int[][] commands) {
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i=0; i<commands.length; i++){
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = commands[i][0] - 1; j < commands[i][1]; j++){
                temp.add(array[j]);
            }
            temp.sort(Comparator.naturalOrder());
            answer.add(temp.get(commands[i][2]-1));
        }
        return answer;
    }
}