class Solution {
    public int solution(String A, String B) {
        int cnt = 0;
        String temp = "";
        while(true){
            if (cnt == A.length())return -1;
            if (A.equals(B))return cnt;
            else {
                cnt++;
                temp = "";
                temp += A.charAt(A.length()-1);
                for (int i=0; i<A.length()-1; i++){
                    temp += A.charAt(i);
                }
                A= temp;
            }
        }
    }
}