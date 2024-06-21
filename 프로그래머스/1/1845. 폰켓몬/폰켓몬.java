import java.util.HashSet;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int arrsize = nums.length / 2;
        HashSet<Integer> mp = new HashSet<>();
        for (int num : nums){
            mp.add(num);
        }
        if (mp.size() >= arrsize) answer = arrsize;
        else answer = mp.size();
        return answer;
    }
}