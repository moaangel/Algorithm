import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String,Integer> mp = new HashMap<>();
        for (int i=0; i< clothes.length; i++){
            if (mp.get(clothes[i][1]) == null || mp.get(clothes[i][1]) == 0){
                mp.put(clothes[i][1], 1);
            }
            else mp.put(clothes[i][1], mp.get(clothes[i][1]) + 1);
        }
        for(String key : mp.keySet()){
          answer *= mp.get(key) + 1;
        }
        answer--;
        return answer;
    }
}