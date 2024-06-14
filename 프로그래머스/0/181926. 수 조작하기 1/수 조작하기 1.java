class Solution {
    public int solution(int n, String control) {
        int answer = n;
        for (int i=0; i<control.length(); i++){
            if (control.substring(i,i+1).equals("w"))answer += 1;
            else if (control.substring(i,i+1).equals("s"))answer -= 1;
            else if (control.substring(i,i+1).equals("d"))answer += 10;
            else if (control.substring(i,i+1).equals("a"))answer -= 10;            
        }
        return answer;
    }
}