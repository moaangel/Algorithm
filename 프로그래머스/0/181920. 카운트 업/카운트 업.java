class Solution {
    public int[] solution(int start_num, int end_num) {
        int[] answer = {};
        answer = new int[end_num - start_num + 1];
        int temp = start_num;
        for (int i = start_num; i <= end_num; i++){
            answer[i - temp] = i;
        }
        return answer;
    }
}