import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String,Integer> mp = new HashMap<>();
        for (String temp : completion){
            if (mp.get(temp) != null){
                mp.put(temp, mp.get(temp) + 1);
            }
            else mp.put(temp, 1);
        }
        for (String s : participant){
            if (mp.get(s) != null){
                if (mp.get(s) == 0){
                    answer = s;
                    break;
                }
                mp.put(s, mp.get(s) - 1);
            }
            else {
                answer = s;
                break;
            }
        }
        return answer;
    }
}