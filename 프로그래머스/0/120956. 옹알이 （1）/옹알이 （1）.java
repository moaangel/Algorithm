class Solution {
    public boolean check(String str, String[] arr){
        int sz = str.length();
        for (int i=0; i<4; i++){
            if (str.contains(arr[i])){
                sz -= arr[i].length(); 
            }
        }
        if (sz == 0) return true;
        else return false;
    }
    
    public int solution(String[] babbling) {
        String[] arr = {"aya", "ye", "woo", "ma"};
        int answer = 0;
        for (int i=0; i<babbling.length; i++){
            if(check(babbling[i], arr))answer++;
        }
        return answer;
    }
}