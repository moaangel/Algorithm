import java.util.HashMap;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashMap<String,Integer> mp = new HashMap<>();
        for (String s : phone_book){
            mp.put(s,1);
        }
        for (int i=0; i<phone_book.length; i++){
            for (int j=0; j< phone_book[i].length(); j++){
                if (mp.containsKey(phone_book[i].substring(0,j))) return false;
            }
        }
        return answer;
    }
}