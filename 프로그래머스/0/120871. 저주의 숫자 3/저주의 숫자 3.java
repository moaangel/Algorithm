class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] threex = new int[101];
        int num = 1;
        int i=1;
        while(i != 101){
            if (num % 3 == 0 || Integer.toString(num).contains("3"))num++;
            else {
                threex[i] = num;
                i++;
                num++;
            }
        }
        answer = threex[n];
        return answer;
    }
}