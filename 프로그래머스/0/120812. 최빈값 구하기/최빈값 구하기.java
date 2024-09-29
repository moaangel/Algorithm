import java.util.*;
class Solution {
    public int solution(int[] array) {
        int answer = 0;
        Map<Integer,Integer> mp = new HashMap<Integer,Integer>();
        for (int i=0; i<array.length;i++){
            if (!mp.containsKey(array[i]))mp.put(array[i], 1);
            else mp.put(array[i], mp.get(array[i])+1);
        }
        
        int cnt = 0;
        int maxValue = 0;
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()){
            if(entry.getValue() > cnt){
                cnt = entry.getValue();
                maxValue = entry.getKey();
            }else if(entry.getValue() == cnt){
                maxValue = -1;
            }

        }
        answer = maxValue;
        return answer;
    }
}