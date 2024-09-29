class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        for (int i=0; i<quiz.length; i++){
            String[] temp = quiz[i].split(" ");
            int first = Integer.parseInt(temp[0]);
            int second = Integer.parseInt(temp[2]);
            int ret = Integer.parseInt(temp[4]);
            if (temp[1].charAt(0) == '+'){
                if (ret == first + second)answer[i] = "O";
                else answer[i] = "X";
            }
            else{
                if (ret == first - second)answer[i] = "O";
                else answer[i] = "X";
            }
        }
        return answer;
    }
}