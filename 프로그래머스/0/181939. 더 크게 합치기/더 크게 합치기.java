class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        String ab = Integer.toString(a) + Integer.toString(b);
        String ba = Integer.toString(b) + Integer.toString(a);
        int abint = Integer.parseInt(ab);
        int baint = Integer.parseInt(ba);
        if (abint > baint) answer = abint;
        else answer = baint;
        return answer;
    }
}