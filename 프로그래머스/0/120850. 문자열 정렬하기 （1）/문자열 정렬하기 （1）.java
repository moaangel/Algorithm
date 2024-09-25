import java.util.*;
 
class Solution {
    public int[] solution(String my_string) {
        int[] answer = {};
        int temp = 0;
        for (int i=0; i<my_string.length(); i++){
            if(my_string.charAt(i) < 'a')temp++;
        }
        answer = new int[temp];
        int j = 0;
        for (int i=0; i<my_string.length(); i++){
            if(my_string.charAt(i) < 'a'){
                answer[j++] = my_string.charAt(i) - '0';
            }
        }
        Arrays.sort(answer);
        return answer;
    }
}