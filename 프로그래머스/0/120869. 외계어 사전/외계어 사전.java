class Solution {
    public int solution(String[] spell, String[] dic) {
        int answer = 2;
        for (int i=0; i<dic.length; i++){
            for (int j =0; j<spell.length; j++){
                if (dic[i].contains(spell[j]) == false) break;
                if (j == spell.length - 1)answer = 1;
            }
            if (answer == 1)break;
        }
        
        
        return answer;
    }
}