class Solution {
    static int[] visited = new int[202];
    static int ret =0;
    
    public void dfs(int idx, int[][] computers){
        for (int i=0; i< computers[idx].length; i++){
            if(computers[idx][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                dfs(i,computers);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        for (int i=0; i<computers.length; i++){
            if (visited[i] == 0){
                visited[i] = 1;
                ret++;
                dfs(i,computers);
            }
        }
        answer = ret;
        return answer;
    }
}