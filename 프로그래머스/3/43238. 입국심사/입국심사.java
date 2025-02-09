class Solution {
    
    static boolean check(long ans, int[] times, int n){
        long temp =0;
        for(int i=0; i<times.length; i++){
            temp += (ans / (long)times[i]);
        }
        return temp >= n;
    }
    
    public long solution(int n, int[] times) {
        long answer = 0;
        long temp =1000000000;
        for (int i=0; i<times.length; i++){
            temp = Math.min(temp, times[i]);
        }
        long l = 1, r = temp * n;
        while(l <= r){
            long mid = (l + r) / 2;
            if(check(mid,times,n)){
                answer = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        
        return answer;
    }
}