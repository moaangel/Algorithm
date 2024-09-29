class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        int s = (total / num) - (num / 2);
        if (total % num != 0) s++;
        for (int i=0; i<num; i++){
            answer[i] = s++;
        }
        return answer;
    }
}