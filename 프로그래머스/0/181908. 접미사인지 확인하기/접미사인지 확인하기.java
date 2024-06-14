class Solution {
    public int solution(String my_string, String is_suffix) {
        int answer = 0;
        int l = is_suffix.length();
        if (is_suffix.length() < my_string.length()){
            if (my_string.substring(my_string.length()-l).equals(is_suffix)) answer = 1;
        }
        else if (is_suffix.length() == my_string.length())
            if (my_string.equals(is_suffix)) answer = 1;
        return answer;
    }
}