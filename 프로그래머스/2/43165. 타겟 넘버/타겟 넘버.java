class Solution {
    static int ret = 0;
    public void dfs(int[] numbers, int idx, int target,int num){
        if(idx == numbers.length){
            if (num == target)ret++;
            return;
        }
        
        dfs(numbers, idx+1, target, num + numbers[idx]);
        dfs(numbers, idx+1, target, num - numbers[idx]);
    }
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(numbers,0,target,0);
        answer = ret;
        return answer;
    }
}