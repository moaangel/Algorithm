class Solution {
    public String[] solution(String[] strArr) {
        String[] answer = {};
        int temp = 0;
        for (int i=0; i<strArr.length; i++){
            if (strArr[i].indexOf("ad") >= 0)continue;
            else temp++;
        }
        answer = new String[temp];
        temp =0;
        for (int i=0; i<strArr.length; i++){
            if (strArr[i].indexOf("ad") >= 0)continue;
            else {
                answer[temp] = strArr[i];
                temp++;
            }
        }
        return answer;
    }
}