import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stk = new Stack<>();

        for (int i=0; i<s.length(); i++){
            if (s.charAt(i) == '(')stk.push('(');
            else{
                if(stk.isEmpty()){
                    stk.push(')');
                }
                else {
                    if (stk.peek() == '(')stk.pop();
                }
            }
        }
        if(!stk.isEmpty())answer = false;
        return answer;
    }
}