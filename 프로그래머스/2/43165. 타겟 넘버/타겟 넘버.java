class Solution {
    int answer = 0;
    
    public void dfs(int idx, int size, int target,int num, int[] numbers){
        if (idx == size){
            if(num == target)answer++;
            return;
        }
        
        dfs(idx+1,size,target,num-numbers[idx],numbers);
        
        dfs(idx+1,size,target,num+numbers[idx],numbers);
    }
    
    public int solution(int[] numbers, int target) {
        
        dfs(0,numbers.length,target,0,numbers);
        return answer;
    }
}