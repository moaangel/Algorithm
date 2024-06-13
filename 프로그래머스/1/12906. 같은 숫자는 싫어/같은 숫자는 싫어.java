import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        
        for (int i=0; i<arr.length; i++){
            if (i == 0) answer.add(arr[0]);
            else {
                if (arr[i] == arr[i-1])continue;
                else {
                    answer.add(arr[i]);
                }
            }
        }
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}