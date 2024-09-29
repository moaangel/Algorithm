class Solution {
    public String solution(String polynomial) {
        String answer = "";
        boolean flag = false;
        for (int i=0; i<polynomial.length(); i++){
            if (polynomial.charAt(i) == ' ')flag = true;
        }
        String[] arr = {};
        if (flag) arr = polynomial.split(" ");
        else {
            return polynomial;
        }
        int left =0;
        int right =0;
        boolean x = false;
        for (int i=0; i<arr.length; i++){
            if (arr[i].charAt(arr[i].length() - 1) == 'x'){
                String temp = "";
                if (arr[i].length() == 1){
                    temp = "1";
                    x = true;
                }
                else{
                    temp = arr[i].substring(0, arr[i].length() -1);
                }    
                left += Integer.parseInt(temp);
            }
            else if (arr[i].charAt(arr[i].length() - 1) == '+') continue;
            else right += Integer.parseInt(arr[i]);
        }
        if (left > 1) {
            
            answer += Integer.toString(left);
            if (right != 0){
                answer += "x + ";
                answer += Integer.toString(right);
            }
            else answer += 'x';
        }
        else {
            if (x){
                answer += "x";
                if (right != 0){
                    answer += " + ";
                    answer +=  Integer.toString(right);
                }
            }
            else answer += Integer.toString(right);
        }
        
        return answer;
    }
}